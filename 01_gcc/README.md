# gcc 컴파일러 공부 일지

## 컴파일러란?
> 컴파일러는 작성된 고급언어부터 기계어로 생성하는 과정이다.

## 실행파지의 과정
1. 고급언어 작성
2. 전처리기 (.i 파일생성)
3. 컴파일 (.o 파일생성)
4. 링킹 (각 .o 연결)
5. 실행파일 생성

## gcc command
1. compile
    ```
    gcc -c <filename.c>
    ```
2. generating runfile
    ```
    gcc <filename.o> -o <생성할_실행파일이름>
    ```
3. header folder path setting