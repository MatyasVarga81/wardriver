# wardriver

Az első variáció szerint az eszköz szkenneli a wifi hálózatokat és az aktuális pozició szerint kiirja a koordinátát, valamint a szkennelt wifi hálózat SSID, RSSI, valamint Chanel információját kiírja egy kijelzőre.

Az építés során több problémába is ütköztem. Először a számítógép nem ismerte fel az eszközt. Ehhez szükséges volt egy drivert letölteni, hogy a mikrokontroller portját felismerje a számítógép. Ehhez a https://community.silabs.com/s/article/downloading-cp210x-drivers-from-windows-update?language=en_US honlapról töltöttem le az anyagokat. 
Ezután szembesültem azzal, hogy a vásárolt kijelző nem műkdöik. Így a módosított program a kijelző helyett az Arduino fejlesztői környezet soros monitorját használja. Ehhez viszont a számítógéphez kell csatlakoztatni az eszközt. Így az eredeti elgondolás egy hordozható eszköz készítésére, sajnos nem valósult meg. ![image0](https://github.com/user-attachments/assets/6dcf46c0-270e-44f0-9972-d79f1aa1c152)
A képen látható összeszerelt állapotban az eszköz a GPS vevővel, a hálózati, vagy powerbankos töltési lehetőséget biztosító modullal és a kijelzővel.

A következő képen látható az Arduino IDE soros monitorja, mely mutatja a program működését és kiírja a szkennelt wifi hálózatok adatait. A GPS koordinátákat nem jelzi a rendszer, nem ismert hiba miatt. Előfordulhat, hogy az épületben nem érzékeli a rendszer a műholdakat, vagy a programban található hiba. 
![image1](https://github.com/user-attachments/assets/579fe6f8-d03c-4d16-be5e-fc74cdb55aa8)
