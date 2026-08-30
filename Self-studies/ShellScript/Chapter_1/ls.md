# 
## 1. 명령어의 타입
* Alias : 명령어와 그것의 옵션에 대한 바로가기; 메모리에 저장되어 있음.
* Function
* Shell built in
* Keyword
* File
___
1. Alias 찾기
```bash
$ type ls
```
2. 명령어 경로도 함께
```bash
$ type -a ls
```
3. 명령어 타입 출력
```bash
$ type -t ls
```
4. 여러 명령어에 대한 출력  
function인 경우 타입과 함께 코드 또한 보여줌.
```bash
$ type ls quote pwd do id
```

## 2. 명령어 PATH
Linux는 프로그램의 경로가 제공될 때 환경변수 PATH에서 실행 파일을 확인.  
일반적으로 현재 디렉터리는 PATH에 없는 경우 검색되지 않음.
___
1. 현재 디렉터리를 PATH 변수에 추가.
```bash
$ export PATH=$PATH:.
```  
PATH 내 경로들은 콜론 **:** 으로 나뉘어져 있음.  
현재 경로를 추가함으로써 현재 경로 내 명령어를 경로 명시없이 실행 가능함.  

2. 경로가 없을 경우에만 경로 생성.
```bash
$ test -d $HOME/bin || mkdir $HOME/bin
```
## 3. vim 설정
vi 혹은 vim의 옵션 설정 시 $HOME/.vimrc 파일 생성 필요.  
+ __showmode__: Ensures we see when we are in insert mode  
+ __nohlsearch__: Does not highlight the words that we have searched for  
+ __autoindent__: We indent our code often; this allows us to return to the last indent level rather than the start of a new line on each carriage return  
+ __tabstop=4__: Sets a tab to be four spaces  
+ __expandtab__: Converts tabs to spaces, which is useful when the file moves to other systems  
+ __syntax on__: Note that this does not use the set command and is used to turn on syntax highlighting

```
setshowmodenohlsearch
setautoindenttabstop=4
setexpandtab
syntax on
```
