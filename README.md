# System_MCU

## Travaux pratiques : Systèmes à microcontroleurs

### 1.2 Le microcontrôleur sous KiCAD

##### 2.

##### 3.

##### 4.

##### 5.

### 3.1 Activation des LL drivers

##### 2. Lors de la génération de code avec la bibliothèque LL, on remarque les changements de synthaxe des appels de fonctions.  

##### 4. __STATIC_INLINE permet de définir une fonction en ligne et de la rendre statique.

##### 5. La fonction est définit aussi dans un .h . Néamoins, __STATIC_INLINE permet une optimisation au niveau compilateur lors de l'appel de fonction. 

### 3.2 LED simple

##### 2. Pour une configuration du timer de la LED à une fréquence 1kHz et une résolution de 8bits, il faut déterminer les valeurs de PSC et ARR comme suivant : 
- Période = (PSC + 1) * (ARR + 1) / Fréquence du clock du timer
- L'horloge du timer est à 32 Mhz. Donc PSC = 125 et ARR = 255.

### 3.3 LED avec timer

##### 3. Les valeurs de PSC et ARR sont 125 et 255 respectivement.



#### 3.4 UART, un simple echo

##### 5.
