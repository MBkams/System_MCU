// Démarre le timer
void LedStart(void);

// Configure le rapport cyclique de la PWM entre 0 et 255
void LedSetValue(unsigned int val);

// À chaque appel, cette fonction incrémente la luminosité de la LED
// Arrivé à la valeur maximale, chaque appel décrémente la LED
void LedPulse(void);
