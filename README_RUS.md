*** Description ***

Разработать программу src/pong.c, представляющую из себя игру для двух 
игроков, схожую с игрой "Pong". Для отображения графики использовать только символьную (ASCII) 
графику (с выводом в терминал). Вам необходимо реализовать пошаговый вариант исключительно в рамках уже изученного материала и стандартной библиотеки.*** 

* ***Управление:***
  
***A/Z и K/M для перемещения ракеток.***

***Space Bar для пропуска действия на очередном шаге игры в пошаговом режиме.***

* ***Графика***

***Поле — прямоугольник 80 на 25 символов.***

***Размер ракетки — 3 символа.***

***размер мяча — 1 символ.***

* ***UI/UX***

***После достижения одним из игроков счета в 21 очко, игра выводит поздравление победителя и завершается.==*** 

## Бонусная часть

Необходимо реализовать Pong в интерактивном режиме (режим игры в реальном времени), используя дополнительные библиотеки для упрощения обработки действий игроков и отображения символьной графики. Код интерактивного режима должен находиться в файле src/pong_interactive.c. Для реализации бонусной части обязательна реализация базовой части сначала.

## Важные замечания

* Игра должна быть разработана на языке C++, в структурном стиле и работать из терминала;
  
* Проверка```cppcheck```, а также стилевым линтером ```clang-format```.

* Инструкция о том, как запустить эти тесты у себя на компьютере, лежит в папке `materials`.


## Some facts.

>Pong, groundbreaking electronic game released in 1972 by the American game manufacturer Atari, Inc. One of the earliest video games, Pong became wildly popular and helped launch the video game industry. The original Pong consisted of two paddles that players used to volley a small ball back and forth across a screen.
>
>The German-born American television engineer Ralph Baer laid the groundwork for Pong in 1958 when he proposed making simple video games that people could play on their home television sets. The Magnavox Odyssey, known as the first console video game system, was released in 1972 and offered a game of table tennis, or Ping-Pong. Atari founder Nolan Bushnell created Pong, his version of this concept, as an arcade game. A small company at the time, Atari began manufacturing the games in an old roller skating rink, and by 1972 the company had sold more than 8,000 Pong arcade machines. In 1975 Atari turned Pong into a console system game. After striking an exclusive deal with Sears, Roebuck and Company, Pong was soon in the homes of many American families. Pong’s popularity declined in the 1980s as video games temporarily went out of style, but it had already secured its place in history as the most popular arcade game up to that time.
>
>In 1974 the makers of the Magnavox Odyssey sued Atari for stealing the concept for Pong. Magnavox won the lawsuit in 1977, upholding the company’s patent, but by then Atari had already licensed the patent for $700,000.
