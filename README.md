# Shared memory and Docker

### Description
Test task in Yadro lab in ETU "LETI", 2025.

### Dependencies
To run program you must have [Docker](https://docs.docker.com/engine/install/ubuntu/) installed.

### Run
To execute programs in Docker container use
```
chmod +x start_docker.sh
./start_docker.sh          # may require sudo
```


### Task

**Необходимо создать 2 программы на языке C/C++:**
- Первая программа должна создать регион разделяемой памяти (shared memory) размером в 1000 байт, записать туда строку “Hello world!” и
вывести в стандартный поток вывода ключ разделяемой памяти. В случае ошибки программа должна вывести код ошибки и расшифровку кода ошибки.
- Вторая программа должна считать ключ разделяемой памяти из вывода первой программы, прочитать содержимое участка памяти и вывести его в
стандартный поток вывода в виде строки. В случае ошибки программа должна вывести код ошибки и расшифровку кода ошибки.
Перед завершением программа должна удалить указанный участок разделяемой памяти для всех процессов.
 
**Требования к выполнению задания:**
- Программы должны запускаться внутри Docker-контейнера. В качестве базового docker образа необходимо использовать официальный образ gcc: gcc:11.3.0
- Необходимо создать свой репозиторий для данного задания. Репозиторий должен содержать файлы исходного кода, dockerfile, скрипты для сборки и запуска задания и инструкцию для запуска и сборки
- Программы не должны использовать сторонние библиотеки для межпроцессного взаимодействия, которые используют механизм разделяемой памяти (необходимо использовать функции стандартной библиотеки)
