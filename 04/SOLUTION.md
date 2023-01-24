# Exercise 04 Solution by Mārtiņš Dāvis Jembergs

## Establish a recurrence equation for $`A_{n}`$

$`A_{n} = A_{n-1} * \frac{3}{4}`$

## Show by complete induction that $`A_{n}=(\frac{3}{4})^{n}*A`$ holds

### Basic step:
$`A_{0} = (\frac{3}{4})^{0} * A = 1 * A = A`$

### Recursive step: 

For simplicity's sake let's assume that the area $`A`$ we're working with is equal to 1. At the first iteration $`\frac{1}{4}`$ is taken away from the original area A, so
$`A_{1} = \frac{3}{4}`$

Next three triangles are removed from the remaining area, having $`\frac{1}{4}`$ of the triangle each. This means that in total 
$`\frac{3}{16}`$ are removed in the second step
$`A_{2} = \frac{3}{4} - \frac{3}{16} = \frac{9}{16} = (\frac{3}{4})^{2}`$

This should mean that the area for $`A_{n}`$ is $`(\frac{3}{4})^{n}`$ for all n. To see whether this is right, we use induction to see whether 
$`A_{n+1} = (\frac{3}{4})^{n+1}`$

### Induction:

$`A_{n+1} = A_{n} - \frac{3^{n}}{4^{n+1}} = \frac{3^{n}}{4^{n}} - \frac{3^{n}}{4^{n+1}} = \frac{4 * 3^{n} - 3^{n}}{4^{n+1}} = \frac{3 * 3^{n}}{4^{n+1}} = \frac{3^{n+1}}{4^{n+1}} = (\frac{3}{4})^{n+1}`$

### Result:
The formula holds since the induction showed that $`A_{n}=(\frac{3}{4})^{n}*A`$ is true for all n.

## What happens in the limit for $`n \xrightarrow{} \infty`$? Determine 
$`\lim_{n \to \infty} A_{n}`$

$`\lim_{n \to \infty} A_{n} = 0`$

The bigger n gets in the formula in Task 2, the smaller the fraction gets until it becomes 0.
