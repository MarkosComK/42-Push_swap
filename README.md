<h1 align="center">
	📖 Push_swap
</h1>

![Push_swap](https://github.com/user-attachments/assets/e5de5dba-bfa2-4136-acb3-b2f0373e109a)

<p align="center">
	<b><i>Development repo for 42cursus Push_swap project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/MarkosComK/42-Common-Core-Guide"><b>42-Common-Core-Guide repo</b></a>.
</p>


<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---
<br>
<!--
<div align="center">
	<img src="https://github.com/MarkosComK/42-Libft/assets/67120870/10a2a298-340e-4a67-96bd-d97716a60526">
</div>
-->

## 🗣️ About

> Push_swap is a sorting algorithm implemented in C. It efficiently sorts a stack of intengers using a series of predefined operations.

<br>

<p align="center">
	<b><i>The project objectives</i></b><br>
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

```sh
./push_swap -38 10 7 42
```

<p>
    <code style="color : green">./push_swap</code> is our program
</p>
<br>
<p>
    <code style="color : orange">38 10 7 42</code>is our input
</p>
<br>
<p>
     <code style="color : green">./push_swap</code>take this input, use the implemented sorting algorithm and return a value (this value is the amount of used operations to sort the values)
</p>
<br>

## Operations?
