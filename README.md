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
- [x]push, [x]rotate, [x]swap testing.
- 범위별로 b로 넘기기 구현
- lis 제외하고 넘겨야함.
- a로 넘기기 구현
- [선택] 넘기기에 드는 최저 비용 계산 함수 구현
