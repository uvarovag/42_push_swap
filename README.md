# 42_push_swap

## The “checker” program
The first, named checker which takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays OK if integers
are sorted. Otherwise, it will display KO.
```
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```
## The “push_swap” program
The second one called push_swap which calculates and displays on the standard
output the smallest progam using Push_swap instruction language that sorts integer arguments received.
There’s only a few moves you’re allowed to used to manipulate the stacks that we’re going to called “Actions”. The main goal of this project is to organize Stack A in as few actions as possible.

```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

## Here’s how they all work:

![sample stacks](https://miro.medium.com/max/700/1*rXKk8juFHQaLzI-uJyEVog.png)

```
The actions are named: sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb.
```

### Sample commands "sa, sb, ss"
![sample comands "sa, sb, ss"](https://miro.medium.com/max/700/1*dAHbFo-fEko25X-C8CVeKw.png)

### Sample comamnds "ra, rb, rr"
![sample comands "ra, rb, rr"](https://miro.medium.com/max/700/1*Iji-cUJbgJ1BRmLjT9Qqkw.png)

### Sample commands "rra, rrb, rrr"
![sample comands "rra, rrb, rrr"](https://miro.medium.com/max/700/1*v8rjNThxCvEIkbDNjomCZg.png)

### Sample commands "pa, pb"
![sample comands "pa, pb"](https://miro.medium.com/max/700/1*kE_2S1E4IoJxRF4eVt6TAQ.png)

[source of images](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

## Makefile rules
* all
* re
* clean
* fclean

