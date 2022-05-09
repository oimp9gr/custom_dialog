# Custom Dialog

![image](https://user-images.githubusercontent.com/35418986/167439329-f1f13ef0-2caf-48cc-b0d3-147cd5e4c4a7.png)


1) Для создания диалога:
```
right click on project -> Add New... -> Qt -> Qt Designer Form Class (создаст класс вместе .ui файлом) -> 
-> выбираем один из Dialog'ов -> (next)...
```
2) Лучше кнопки `ok/cancel` добавлять самому, т.к., если использовать стандартные (то бишь сразу создавать диалог с кнопками), 
то они, почему-то, автоматически завершают диалог при нажатии.
3) В этом примере слоты `on_first_name_lineEdit_textChanged`, `on_password_lineEdit_textChanged`, `on_email_lineEdit_textChanged` нужны для того, 
чтобы обрабатывать обязательные для ввода поля и не давать завершать диалог.
![image](https://user-images.githubusercontent.com/35418986/167438006-0d9cd4c3-152a-4def-82cf-d988c4a7db56.png)
4) При нажатии кнопки `ok` в диалоге вызывается метод `on_ok_pushButton_clicked`. В нём, при правильно заполненных полях, вызывается метод `collect_data`, 
который заполняет структуру `data` внутри класса `Dialog`. Методы `accept` и `reject` устанавливают соответствующий код возврата (`enum DialogCode`).
5) Внутри `on_pushButton_clicked` в Widget.cpp мы этот код возврата обрабатываем.
