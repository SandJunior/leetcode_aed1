bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int stackIndex = 0;
    for (int i = 0; i < pushedSize; i++) {
        pushed[stackIndex++] = pushed[i];
        while (stackIndex > 0 && pushed[stackIndex - 1] == popped[0]) {
            stackIndex--;
            popped++;
            poppedSize--;
        }
    }
    return poppedSize == 0;

}