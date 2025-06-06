#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura do aluno (nó da árvore binária de busca)
typedef struct Student {
    char name[50];
    int registration;
    float grade;
    struct Student* left;
    struct Student* right;
} Student;

// criar um novo nó de aluno
Student* createStudent(char name[], int registration, float grade) {
    Student* newNode = (Student*) malloc(sizeof(Student));
    if (newNode != NULL) {
        strcpy(newNode->name, name);
        newNode->registration = registration;
        newNode->grade = grade;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// inserir um aluno na árvore binária de busca:
Student* insertStudent(Student* root, char name[], int registration, float grade) {
    if (root == NULL)
        return createStudent(name, registration, grade);
    if (registration < root->registration)
        root->left = insertStudent(root->left, name, registration, grade);
    else if (registration > root->registration)
        root->right = insertStudent(root->right, name, registration, grade);
    return root;
}

// 3. Implemente um algoritmo para buscar um aluno pelo nome
Student* searchByName(Student* root, const char* name) {
    if (root == NULL)
        return NULL;
    if (strcmp(name, root->name) == 0)
        return root;
    Student* leftResult = searchByName(root->left, name);
    if (leftResult != NULL)
        return leftResult;
    return searchByName(root->right, name);
}

// 4. Crie um algoritmo para calcular a media das notas dos alunos. 
void sumGrades(Student* root, float* sum, int* count) {
    if (root != NULL) {
        *sum += root->grade;
        (*count)++;
        sumGrades(root->left, sum, count);
        sumGrades(root->right, sum, count);
    }
}

float averageGrades(Student* root) {
    float sum = 0;
    int count = 0;
    sumGrades(root, &sum, &count);
    return (count > 0) ? sum / count : 0;
}

int main() {
    Student* root = NULL;

    root = insertStudent(root, "Caio", 123, 8.5);
    root = insertStudent(root, "Pedro Henrique", 456, 7.0);
    root = insertStudent(root, "João Carlos", 789, 9.2);

    // Test search by name
    Student* found = searchByName(root, "Pedro Henrique");
    if (found != NULL)
        printf("Student found: %s, Grade: %.2f\n", found->name, found->grade);
    else
        printf("Student not found.\n");

 
    printf("Average of grades: %.2f\n", averageGrades(root));

    

    return 0;
}