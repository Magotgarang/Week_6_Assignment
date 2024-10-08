#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENT_COUNT 100  // Maximum number of patients that can be stored

// Structure to represent a patient
struct PatientRecord {
    char patientName[50];  // Name of the patient
    int conditionSeverity;  // Severity of the patient's condition
};

// Structure to represent a max heap
struct PatientHeap {
    int currentSize;                // Current number of patients in the heap
    struct PatientRecord patients[MAX_PATIENT_COUNT];  // Array to store patients
};

// Function to swap two patients in the heap
void swapPatients(struct PatientRecord *a, struct PatientRecord *b) {
    struct PatientRecord temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the max heap property
void adjustHeap(struct PatientHeap *heap, int index) {
    int highest = index;
    int leftChild = 2 * index + 1;  // Index of the left child
    int rightChild = 2 * index + 2; // Index of the right child

    // Check if the left child is greater than the current highest
    if (leftChild < heap->currentSize && heap->patients[leftChild].conditionSeverity > heap->patients[highest].conditionSeverity) {
        highest = leftChild;
    }

    // Check if the right child is greater than the current highest
    if (rightChild < heap->currentSize && heap->patients[rightChild].conditionSeverity > heap->patients[highest].conditionSeverity) {
        highest = rightChild;
    }

    // If the highest is not the current index, swap and continue heapifying
    if (highest != index) {
        swapPatients(&heap->patients[index], &heap->patients[highest]);
        adjustHeap(heap, highest); // Recursive call to heapify the affected subtree
    }
}

// Function to add a patient to the heap
void addPatient(struct PatientHeap *heap, const char *name, int severity) {
    if (heap->currentSize >= MAX_PATIENT_COUNT) {
        printf("Cannot add more patients. Maximum limit reached.\n");
        return;
    }

    struct PatientRecord newPatient;
    strcpy(newPatient.patientName, name);
    newPatient.conditionSeverity = severity;

    heap->patients[heap->currentSize] = newPatient; // Place new patient at the end
    heap->currentSize++; // Increment the size of the heap

    int index = heap->currentSize - 1;

    // Fix the max heap property if it is violated
    while (index != 0 && heap->patients[(index - 1) / 2].conditionSeverity < heap->patients[index].conditionSeverity) {
        swapPatients(&heap->patients[index], &heap->patients[(index - 1) / 2]);
        index = (index - 1) / 2; // Move up to the parent
    }
}

// Function to display the heap contents
void displayHeap(const struct PatientHeap *heap) {
    for (int i = 0; i < heap->currentSize; i++) {
        printf("Patient Name: %s, Severity: %d\n", heap->patients[i].patientName, heap->patients[i].conditionSeverity);
    }
}

// Main function to demonstrate the heap functionality
int main() {
    struct PatientHeap heap; // Create a heap to manage patients
    heap.currentSize = 0;    // Initialize the heap size to 0

    // Adding patients to the heap
    addPatient(&heap, "Andrew", 5);
    addPatient(&heap, "Samuel", 3);
    addPatient(&heap, "Ezekiel", 7);

    // Display the patients in the heap
    printf("Current patient priority list:\n");
    displayHeap(&heap);

    return 0; // Exit the program
}
