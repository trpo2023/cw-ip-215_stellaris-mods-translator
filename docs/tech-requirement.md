Функциональность проекта:
    Проект решает проблему отображения внутриигровых надписей модификаций.
    Проект локализует модификации, не имеющие перевода на нужный язык.

Формат входных данных:
    С клавиатуры.

Интерфейс приложения:
    Приложение является фоновым процессом. Пользователь только вводит входные данные.
    Приложение использует сетевой сервис. Данные для перевода отправляются на сайт API переводчика.

Если приложение принимает аргументы командной строки, то их формат и описание:
    Приложение принимает три аргумента командной строки: API-ключ, путь к модификациям и тип работы программы.

Если предполагается использовать чтение исходных данных извне программы:
    Программа по указанному пути к модификациям считывает данные из файлов локализации.
