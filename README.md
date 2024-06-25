# 42_push_swap
This repo is push_swap in 42.  
Just writing my algo and thinking.  

## Prepare
1. Copying libft and ft_printf
2. Create Makefile
3. Create push_swap.c and push_swap.h

## Start
1. Searching which func use
2. Thinking algo

## Test
1. ./push_swap 01 02 03 030

## Benchmark
1. 3 values => less than 3 instr
2. 5 values => less than 8 instr
3. 100 values =>  
                 less than 700: 5  
                 less than 900: 4  
                 less than 1100: 3  
                 less than 1300: 2  
                 less than 1500: 1  
4. 500 values =>  
                 less than 5500: 5  
                 less than 7000: 4  
                 less than 8500: 3  
                 less than 10000: 2  
                 less than 11500: 1  

## todo
- [x] push, [x]rotate, [x]swap testing.
- [x] 범위별로 b로 넘기기 구현
- [x] lis 제외하고 넘겨야함.
- [x] a로 넘기기 구현
- [선택] 넘기기에 드는 최저 비용 계산 함수 구현
- 현재 100개일때 700대 -> 구역 5개로
- 500개일때 7000대 -> 구역 8~10개로
- 둘다 4점획득 개꿀~~
- 아니네 500개일땐 3점...
---
## 2024-06-20
- 거의 완성함.
- tester만 돌려보면 될 듯
- lis 사용함.
- a에서 정렬해주고 끝내면 됨.
- bonus만들어야함.
## 2024-06-21 to-do
- bonus part 구현
- [x] 입력 파트 구현
- norminette 맞추기
## 2024-06-22 to-do
- bonus제발 구현
- norminette 맞추기
## 2024-06-25 to-do
- 보너스 구현 거의 완료
- norminette 거의 완료
