#ifndef __PATIENT_H
#define __PATIENT_H
struct Patient {
public:
    int card;
    int illness;
    char doctor[16];
    Patient(int card, int illness, char* doctor);
};
#endif // !__PATIENT_H



