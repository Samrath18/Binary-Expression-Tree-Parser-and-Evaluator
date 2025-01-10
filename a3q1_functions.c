#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "a3q1_header.h"

Variable variables[10];
int varCount = 0;

// Function to create new node with given data
Node *createNode(char *data) {
  Node *node = (Node *)malloc(sizeof(Node));

  strcpy(node->data, data);
  node->left = node->right = NULL;

  return node;
}

// Function to parse a number or variable from expression
void parseOperand(char *expr, int *index, char *result) {
  int x = 0;

  while (isalnum(expr[*index]) || expr[*index] == '.') {
    result[x++] = expr[(*index)++];
  }

  result[x] = '\0';
}

// Recursively parse expression to build binary expression tree
Node *parseExpression(char *expr) {
  int index = 0;

  return parseExpressionRecursion(expr, &index);
}

Node *parseExpressionRecursion(char *expr, int *index) {
  if (expr[*index] == '(') (*index)++;  // Skip '(' character

  Node *left, *right, *node;
  char data[10];

  if (expr[*index] == '(') {
    left = parseExpressionRecursion(expr, index);  // Parse left subtree

    if (left == NULL) {
      return NULL;
    }
  } else {
    parseOperand(expr, index, data);

    if (data[0] == '\0') {
      return NULL;  // Invalid operand
    }

    left = createNode(data);  // Leaf node
  }

  if (strchr("+-*/", expr[*index])) {
    char op[2] = {expr[*index], '\0'};
    node = createNode(op);
    (*index)++;  // Skip operator
  } else {
    return NULL;  // Invalid operator
  }

  if (expr[*index] == '(') {
    right = parseExpressionRecursion(expr, index);  // Parse right subtree

    if (right == NULL) {
      return NULL;
    }
  } else {
    parseOperand(expr, index, data);

    if (data[0] == '\0') {
      return NULL;  // Invalid operand
    }

    right = createNode(data);  // Leaf node
  }

  if (expr[*index] == ')') {
    (*index)++;  // Skip ')' character
  } else {
    return NULL;  // Mismatched parentheses
  }

  node->left = left;
  node->right = right;

  return node;
}

// Preorder traversal
void preorder(Node *root) {
  if (root == NULL) {
    return;
  }

  printf("%s ", root->data);
  preorder(root->left);
  preorder(root->right);
}

// Inorder traversal  full parentheses
void inorder(Node *root) {
  if (root == NULL) {
    return;
  }
  if (root->left && root->right) {
    printf("(");
  }

  inorder(root->left);
  printf("%s", root->data);
  
  inorder(root->right);

  if (root->left && root->right) {
    printf(")");
  }
}

// Postorder traversal
void postorder(Node *root) {
  if (root == NULL) {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  printf("%s ", root->data);
}

// Prompt user for variable values
void promptVariables(Node *root) {
  if (root == NULL) {
    return;
  }
  if (isalpha(root->data[0])) {
    int found = 0;

    for (int i = 0; i < varCount; i++) {
      if (strcmp(variables[i].varName, root->data) == 0) {
        found = 1;

        break;
      }
    }
    if (!found) {
      printf("Enter value for %s: ", root->data);

      float value;
      scanf("%f", &value);

      strcpy(variables[varCount].varName, root->data);
      variables[varCount].value = value;
      varCount++;
    }
  }

  promptVariables(root->left);
  promptVariables(root->right);
}

// Calculate expression result with division by zero check
float calculate(Node *root) {
  if (root == NULL) {
    return 0;
  }

  // If node is a number, return its value
  if (isdigit(root->data[0]) || root->data[0] == '.') {
    return atof(root->data);
  }

  // If node is a variable, return its value from variables array
  if (isalpha(root->data[0])) {
    for (int i = 0; i < varCount; i++) {
      if (strcmp(variables[i].varName, root->data) == 0) {
        return variables[i].value;
      }
    }

    printf("Variable %s not found. Using 0 as default.\n", root->data);

    return 0;  // Default value if variable not found
  }

  // Recursive calculation for operators
  float left = calculate(root->left);
  float right = calculate(root->right);

  if (strcmp(root->data, "+") == 0) {
    return left + right;
  }
  if (strcmp(root->data, "-") == 0) {
    return left - right;
  }
  if (strcmp(root->data, "*") == 0) {
    return left * right;
  }
  if (strcmp(root->data, "/") == 0) {
    if (right == 0) {
      printf("Error: Division by zero.\n");

      return 0;
    }

    return left / right;
  }

  printf("Unknown operator %s.\n", root->data);

  return 0;
}