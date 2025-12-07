/*  Для работы с кнопками установите библиотеку SavaButton https://github.com/sava-74/SavaButton.git
*   Пример 2: Переключатель (T-Триггер)
*   Этот пример реализует классический выключатель света.
*   Нажали кнопку -> "Свет" включился.
*   Отпустили -> "Свет" горит.
*   Нажали еще раз -> "Свет" выключился.
*/

#include <SavaButton.h>
#include <SavaTrig.h>

SavaButton btn; // Кнопка управления
SavaTrig myToggle;     // Экземпляр Т-триггера

// Переменная для отслеживания изменений в Serial
bool lastOutput = false;

void setup() {
  Serial.begin(9600);
  btn(12);
  
  Serial.println("--- Пример 2 : TT тригер(Тумблер) ---");
  Serial.println("Нажмите кнопку на выводе 12 для включения/ выключения");
}

void loop() {
  // 1. Читаем кнопку
  bool btnState = btn.read();

  // 2. Подаем сигнал в Т-триггер
  // Он сам поймает нажатие и переключит свое состояние
  bool lampState = myToggle.TT(btnState);

  // 3. Вывод в порт (только если состояние изменилось)
  if (lampState != lastOutput) {
    lastOutput = lampState;
    
    if (lampState) {
      Serial.println("Сосотояние лампы: [ Включена ]");
    } else {
      Serial.println("Сосотояние лампы: [ Выключена ]");
    }
  }
}