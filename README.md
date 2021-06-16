# diva2

## 꿀팁
### port번호 죽이기
현재 PORTNUM이 현재 사용중인지 확인하기
`sudo lsof -i:[PORTNUM]`
example:
`sudo lsof -i:9899`

해당 PORTNUM 지우기
`sudo kill -9 PORTNUM`
example:
`sudo kill -9 30217`
