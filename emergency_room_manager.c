#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENT_COUNT 100  // Maximum number of patients

// Structure to represent a patient
struct PatientRecord {
    char patientName[50];
    int conditionSeverity;
};

// Structure to represent a max heap
struct PatientHeap {
    int currentSize;
    struct PatientRecord patients[MAX_PATIENT_COUNT];
};

// Swap function
void swapPatients(struct PatientRecord *a, struct PatientRecord *b) {
    struct PatientRecord temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain the max-heap property
void adjustHeap(struct PatientHeap *heap, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->currentSize && heap->patients[leftChild].conditionSeverity > heap->patients[largest].conditionSeverity)
        largest = leftChild;
    if (rightChild < heap->currentSize && heap->patients[rightChild].conditionSeverity > heap->patients[largest].conditionSeverity)
        largest = rightChild;

    if (largest != index) {
        swapPatients(&heap->patients[index], &heap->patients[largest]);
        adjustHeap(heap, largest);
    }
}

// Insert patient into heap
void addPatient(struct PatientHeap *heap, const char *name, int severity) {
    if (heap->currentSize >= MAX_PATIENT_COUNT) {
        printf("Cannot add more patients. Maximum limit reached.\n");
        return;
    }

    struct PatientRecord newPatient;
    strcpy(newPatient.patientName, name);
    newPatient.conditionSeverity = severity;

    heap->patients[heap->currentSize] = newPatient;
    heap->currentSize++;

    int i = heap->currentSize - 1;
    while (i != 0 && heap->patients[(i - 1) / 2].conditionSeverity < heap->patients[i].conditionSeverity) {
        swapPatients(&heap->patients[i], &heap->patients[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract the patient with the highest severity (root)
struct PatientRecord extractMax(struct PatientHeap *heap) {
    if (heap->currentSize <= 0) {
        printf("No patients in the heap.\n");
        struct PatientRecord empty = {"", -1};
        return empty;
    }

    struct PatientRecord root = heap->patients[0];
    heap->patients[0] = heap->patients[heap->currentSize - 1];
    heap->currentSize--;
    adjustHeap(heap, 0);

    return root;
}

// Update a patient's severity
void updateSeverity(struct PatientHeap *heap, int index, int newSeverity) {
    int oldSeverity = heap->patients[index].conditionSeverity;
    heap->patients[index].conditionSeverity = newSeverity;

    if (newSeverity > oldSeverity) {
        while (index != 0 && heap->patients[(index - 1) / 2].conditionSeverity < heap->patients[index].conditionSeverity) {
            swapPatients(&heap->patients[index], &heap->patients[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    } else {
        adjustHeap(heap, index);
    }
}

// Display the current queue of patients
void displayHeap(const struct PatientHeap *heap) {
    for (int i = 0; i < heap->currentSize; i++) {
        printf("Patient Name: %s, Severity: %d\n", heap->patients[i].patientName, heap->patients[i].conditionSeverity);
    }
}

// Main function
int main() {
    struct PatientHeap heap;
    heap.currentSize = 0;

    addPatient(&heap, "Andrew", 5);
    addPatient(&heap, "Ezekiel", 3);
    addPatient(&heap, "Samuel", 7);

    printf("Current patient queue:\n");
    displayHeap(&heap);

    printf("\nTreating highest severity patient:\n");
    struct PatientRecord patientToTreat = extractMax(&heap);
    printf("Treating patient: %s with severity %d\n", patientToTreat.patientName, patientToTreat.conditionSeverity);

    printf("\nUpdated patient queue:\n");
    displayHeap(&heap);

    return 0;
}
