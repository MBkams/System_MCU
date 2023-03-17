# System_MCU

## Travaux pratiques : Systèmes à microcontroleurs

### 1.2 Le microcontrôleur sous KiCAD

13) Pourquoi PB9 est relié à la maase?
14) Quel est le rôle de L1, C5 et C7 ? :
    Le rôle des composants L1, C5 et C7 est de filtrer la tension d'alimentation venant du 3,3V. L'association de ces composants forme un filtre passe-bas du second ordre.

### 3. Le reste du schéma

3) Quelle page de la datasheet indique les valeurs des condensateurs ? :
   La page 1 : elle indique que la capacité doit être au moins de 0,47uF.
   La page 3 : elle indique que la capacité à une valeur typique de 1uF.
4) Quelle page de la datasheet nous indique les valeurs de condensateurs ? :
   la valeur de condensateurs des  du DAC est donnée en page 25 de la datasheet.

6) Quel est le rôle de la broche CS ?
La broche CS correspond au « Chip Enable » . Un état bas sur cette broche permet d’activer la clock et les données.

7) Quel est le rôle de la broche LDAC ?
La croche LDAC est utilisée pour transférer le registre de verrouillage d'entrée vers le registre du DAC. Lorsque cette broche est à létat bas, la sortie VOUT est mis à jour avec le contenu du registre d'entrée. 

8) Pourquoi le signal MISO n’est pas utilisé ?
Le signal MISO a été connecté directement au STM32, comme décrit dans la procédure. Le signal MOSI transmets les données du maître, le STM32, jusqu’à l’esclave et inversement pour le signal MISO (de l’esclave au maître). Comme on souhaite seulement communiquer du maître jusqu’à l’esclave, on a pas besoin d’utiliser le signal MISO.

10) Où trouve-t-on les indications du pinout du connecteur SWD ?
On trouve ces indications dans le manuel d’utilisation.

### 4. Affectation des empreintes

3) Que signifie 0805 ? 0603 ? 1206 ?
Ces informations corresponent aux dimensions des composants. Exemple avec 0805 : le composent mesure 0.08 pouces sur 0.05 pouces. (a noter que 0.1 pouce égal 2,54 mm)

4) Que signifie LQFP ? SOT-223 ? SOIC ?
QFP décrit le package du composent, cela signifie : Quad Flat Package, qui est un circuit intégré monté en surface. Et LQFP signifie : Low-profile Quad Flat Package, voulant dire que le package est plus petit que le PCB.

SOT : Small-Outline Transistor.
C'est une famille de transistor discrets pour des montages en surface.

SOIC : Small Outline Integrated Circuit 
Boîtier de circuit intégré monté en surface qui occupe une surface inférieure d’environ 30 à 50% à celle d’un boîtier double en ligne (DIP) équivalent, avec une épaisseur typique inférieure de 70%. Ils sont généralement disponibles dans les mêmes brochages que leurs homologues DIP IC. La convention pour nommer le package est SOIC ou SO suivi du nombre de broches. Par exemple, un 4011 à 14 broches serait logé dans un boîtier SOIC-14 ou SO-14. (oui ça vient de Wikipédia, mais on a lu !)

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

##### 6. La routine d'interruption se situe au nivau TIM21_IRQHandler(void).

##### 7. Avec l'utilisation de la bibliothèque LL, il doit manquer la remise à zero du flag.

##### 8. Cela peut entraîner la routine d'interuption en boucle.

##### 9. Il faut faire une remise à zero du flag.

### 3.4 UART, un simple echo

##### 5. J'ai modifié la défintion des fonctions SerialTransmit et SerialReceiveChar afin de les adapter avec HAL :)
