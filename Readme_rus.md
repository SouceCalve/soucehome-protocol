RU [EN](Readme.md)

# Soucehome

Протокол Soucehome - ещё одна реализация протокола умного дома.

## Установка

Склонируйте репозиторий

```bash
git clone github.com/homayk228/soucehome-protocol/
```
Откройте receiver.ino и master.ino в Arduino IDE

Прошейте в мастера или ведомых

## Описание протокола

Протокол не поддерживает никакого шифрование, используйте на свой страх и риск!

Работает в режиме half-duplex, управляет передачей мастер:

Мастер[сообщение_сделай_чтото]==>ведомый

Ведомый что-то делает и отправляет сообщение о успешном выполнении обратно

ведомый[сообщение_сделал]==>мастер

### Команды

From 0x00 to 0xff:

0x00 - master ping slave

Пингует ведомого для проверки в сети ли он.

0x01 - opens door

Открывает дверь/домофон.

0x02 slave answer

Отвечает мастеру о том, что он в сети.

0x03 OK

Отвечает мастеру что его команда выполнена успешно.

0x04 read

Не реализовано. Читает из сенсора или блока памяти и отправляет мастеру. Что прочитать и получить выбирает мастер.

0x05 load

Не реализовано. Загружает информацию с мастера в ведомого.

0x06 data

Не реализовано. Флаг, по которому можно понять, что дальше идут данные до конца сообщения.

Адреса команд с 0x07 по 0xff не используются.

## Адресация на шине

Один мастер и 254 ведомых(от 0x01 до 0xff).

## Изменения в протоколе
Все команды прописаны в блоке Settings в начале кода.


## Вклад в разработку

Любой вклад приветствуется. Для координальных изменений, сначала откройте issue для обсуждения.

## Лицензия

[GPL-3.0]

