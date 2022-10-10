#include "Patient.h"
Patient::Patient(int card, int illness, char* doctor) {
    this->card = card;
    this->illness = illness;
    for (int i = 0; i < 16; i++) {
        this->doctor[i] = doctor[i];
    }
}