<h1 align="center">
	📖 Push_swap
</h1>

![Push_swap](https://github.com/user-attachments/assets/e5de5dba-bfa2-4136-acb3-b2f0373e109a)

<p align="center">
	<b><i>Development repo for 42cursus Push_swap project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/MarkosComK/42-Common-Core-Guide"><b>42-Common-Core-Guide repo</b></a>.
</p>
<p align="center">
	Don`t forget to give it a ⭐<strong>Star</strong>.
</p>

<!---
<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

<div align="center">
	<img src="https://github.com/MarkosComK/42-Libft/assets/67120870/10a2a298-340e-4a67-96bd-d97716a60526">
</div>
-->

## 🗣️ About

> Push_swap is a sorting algorithm implemented in C. It efficiently sorts a stack of intengers using a series of predefined operations.

<br>

<p align="center">
![push_swap](https://github.com/user-attachments/assets/884ae181-eb62-407a-af90-b0aa4e6645a5)
</p>

<br>
<p>
Before reviewing my code, I strongly advise against analyzing it in its current state. It's quite disorganized, reflecting my early attempts at tackling the Pushswap project. While it may not be a masterpiece of code, it serves as a starting point for my learning journey.
</p>
<p>
<strong>Don't worry, though</strong>. At the end of this file, I'll share some solutions that helped me successfully complete the project. Additionally, I've included detailed documentation that I found to be very helpful in understanding and improving my code.
</p>

<br>

<p align="center">
	<b><i>The project objectives ✍️</i></b><br>
</p>

<p align="center">
    Basicaly we have two stacks (don`t worry if you don`t understand any concept or word yet, they`ll be explained later on) <i>A</i> and <i>B</i> then we gonna create a program that implemnts a sorting algorithm which will use those two stacks to <strong><i>sort</i></strong> the stacks.
</p>

| Stacks |   A   |   B   |
| :---:  | :---: | :---: |
|        |  -38  |       |
|        |   10  |       |
|        |   7   |       |
|        |   42  |       |

<p>
    Our program works this way:
</p>

```console
./push_swap -38 10 7 42
```

<p>
    <code style="color: cyan">./push_swap</code> is our program
</p>
<br>
<p>
    <code style="color: orange">38 10 7 42</code> is our input
</p>
<br>
<p>
     <code style="color: cyan">./push_swap</code> take this input, use the implemented sorting algorithm and return a value (this value is the amount of used operations to sort the values)
</p>
<br>

## Operations ? ⚙️

- what are these <strong>operations</strong> ?

We have a pre-set of operations to use. they are:

- swap
- rotate
- reverse rotate
- push

### ok, but. How do i use all this information ?

Well. Now thigs will start make some sense. Let`s see step by step.

remember these numbers <code>38 10 7 42</code> let`s see our program working and you will understand why we started talking about all of that.

let`s run our program

```console
./push_swap 38 10 7 42
pb
sa
pa
```
pb, sa, pa?

### first let`s take a look at our starting point (our stacks)

| Stacks |   A   |   B   |
| :---:  | :---: | :---: |
|        |  -38  |       |
|        |   10  |       |
|        |   7   |       |
|        |   42  |       |

### now we`re going to see each operation of our program(pb, sa, pa)

1. <strong>pb</strong> stands for <strong>push B</strong> so our first operation in our program is push our first value to stack b

| Stacks |   A   |   B   |
| :---:  | :---: | :---: |
|        |   ->  |  -38  |
|        |   10  |       |
|        |   7   |       |
|        |   42  |       |

2. Next operation is <strong>sa</strong> which is <strong>swap A</strong>. Gonna swap the first two items of <strong>stack A</strong>:

<table>
<tr><th>Before Swap A</th><th>After Swap A</th></tr>
<tr><td>

| Stacks |   A   |   B   |
|--------|-------|-------|
|        |       |  -38  |
|   ->   |   10  |       |
|   ->   |   7   |       |
|        |   42  |       |

</td><td>

| Stacks |   A   |   B   |
|--------|-------|-------|
|        |       |  -38  |
|        |   7   |       |
|        |   10  |       |
|        |   42  |       |

</td></tr> </table>

3. Now lets see our last operation happening; <strong>PA</strong> which stands for <strong>Push A</strong>

<table>
<tr><th>Before Push A</th><th>After Push A</th></tr>
<tr><td>

| Stacks |   A   |   B   |
|--------|-------|-------|
|        |       |  -38  |
|        |   7   |       |
|        |   10  |       |
|        |   42  |       |

</td><td>

| Stacks |   A   |   B   |
|--------|-------|-------|
|        |   -38 |       |
|        |   7   |       |
|        |   10  |       |
|        |   42  |       |

</td></tr> </table>

Our stack A at the beginning was

```console
-38 10 7 42
```

Now is

```console
-38 7 10 42
```

It is in ascending order! that`s what we wanted to have.

<br>
Now go back to the beginning of our program running to wach again each step.

## Ok, what now?

Well, now you need to start code. What i recommend:
Start with the stack_a creation, receive the args, transform them into values and place into the stack - I did this using linked list (to be honest i don`t know yet if there is another solution than linked lists).

Its everything working properly? 

- Yes:

So start building te functions in the subject (push, swap, rotate [...]) and don't forget to test them a lot with your stack_a. That's a good starting point and it will take a lot of time to do all of that, but you`ll understand the main concept of Push_swap after that.

## recapitulating ✍️

- Our program will receive intengers.
- will take these intengers and use both stacks <strong>A</strong> and <strong>B</strong> to put them in ascending order
- will use the operations provided in the subject (pa, pb, sa, sb...) to order them.

This sould give you a god starting point to create your own push_swap. Remember, you wi`ll implement a sorting algorithm to use both stacks do what you have to. Try by your own, then come back here i you need to watch the next steps. I will update this README to help everyone. don not forget to give me a ⭐<strong>Star</strong>

## Useful resources

* [Algorithm - With index](https://github.com/VBrazhnik/Push_swap/wiki/Algorithm)
* [Algorithm - Turk](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
* [Slution - @SopadeGalinha](https://github.com/SopadeGalinha/42-Push_Swap)
* [Article - The least amount of moves with 2 stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
* [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)
