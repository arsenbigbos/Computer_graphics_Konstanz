# Exercise 03

Deadline: 2022-11-14 10:00

## 1. Written

Please put your solution in the file `SOLUTION.md`. You should format your math in LaTeX-Syntax by using the Dollar signs ``$` `` and `` `$`` or within a code block with the language defined as `math`. These are then rendered in _Gitlab_ using `KaTeX`:

````markdown
This math is inline $`a^2+b^2=c^2`$.

This is on a separate line

```math
a^2+b^2=c^2
```
````
yields:

This math is inline $`a^2+b^2=c^2`$.

This is on a separate line

```math
a^2+b^2=c^2
```

For _Visual Studio Code_ there are two useful extensions which allow you to see your rendered result by opening a preview of `SOLUTION.md`:
* [Markdown All in One](https://marketplace.visualstudio.com/items?itemName=yzhang.markdown-all-in-one)
* [Markdown+Math](https://marketplace.visualstudio.com/items?itemName=goessner.mdmath) (Muss auf _GitLab_ umgestellt werden)

**IMPORTANT**: Please make an effort to format this in a readable manner. For math tasks in later exercises we can deduct points if you hand in malformatted or misleading math code. Also, *explain* what you are doing if it is nonobvious and give all steps of your solution.

### 1.1. Rendering Equation
The rendering equation describes the light emitted from each point in a scene accoridng to the rules of geometric optics and can be written as follows:
```math
L_s(x, \omega) = E(x, \omega) + \int_\Omega f_r(x,\omega^\prime, \omega) L_i(x,\omega^\prime) \cos (\theta) d\omega^\prime
```
Explain briefly the meaning of the following variables. (6 Points)

1. $`L_s(x, \omega)`$
2. $`E(x, \omega)`$
3. $`\Omega`$
4. $`f_r(x,\omega^\prime, \omega)`$
5. $`L_i(x, \omega^\prime)`$
6. $`\cos (\theta)`$


### 1.2. Raytracing vs Radiosity
Name at least three difference between Raytracing and Radiosity. (2 Points).


## 2. Programming
In this exercise we will set up and use _OpenGL_ for the first time. The important functions you will encounter are:

### 2.1 Framework overview
* `cg::View` opens a window, in which you can see the rendering result of your OpenGL code.
* `cg::View::loop()` contains the _render loop_, which renders one frame per iteration.
* `cg::Program` creates a program which loads Shader files, compiles them and passes them to the GPU. OpenGL code (also called glsl) can be reloaded and swapped out at runtime and is separate from your C++ code.
* `cg::Buffer` creates a _Buffer_, which you can use to pass data, such as vertices, to the GPU. This is your only interface to get data into the shader. If a shader expects a certain type of input, you must either provide it via this buffer or from another shader.

The goal of this exercise is to get the framework to run and to submit a screenshot of the window which is created in main. (2 Points) If you installed the required packages via vcpkg as described in exercise 01, this should work right away. You will see a 2D version of the _Sierpiński-Triangle_, being rendered with OpenGL. You can change the number of subidivisions by changing the value of `num_recursion`.




Total: 10 Points
