ExamRoom* createSeat(int pos) {
    ExamRoom* newSeat = (struct ExamRoom*)malloc(sizeof(struct ExamRoom));
    newSeat->position = pos;
    newSeat->next = NULL;
    return newSeat;
}

ExamRoom* examRoomCreate(int N) {
    ExamRoom* exam = (ExamRoom*)malloc(sizeof(ExamRoom));
    exam->n = N;
    exam->seats = createSeat(-1);
    return exam;
}

int seat(ExamRoom* obj) {
    Seat* curr = obj->seats;
    int maxDist = 0, pos = 0;

    while (curr->next != NULL) {
        int currPos = curr->position;
        int nextPos = curr->next->position;

        int dist = (nextPos - currPos) / 2;
        if (dist > maxDist) {
            maxDist = dist;
            pos = (nextPos + currPos) / 2; 
        }
        curr = curr->next;
    }
    if (obj->n - 1 - curr->position > maxDist) {
        pos = obj->n - 1;
    }
    Seat* newSeat = createSeat(pos);
    newSeat->next = curr->next;
    curr->next = newSeat;

    return pos;
}

void examRoomLeave(ExamRoom* obj, int p) {
    Seat* prev = obj->seats;
    Seat* curr = prev->next;

    while (curr != NULL && curr->position != p) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }
}

void examRoomFree(ExamRoom* obj) {
    Seat* curr = obj->seats;
    while (curr != NULL) {
        Seat* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}