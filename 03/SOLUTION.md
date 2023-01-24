# Exercise 03 Solution

### 1.1. Rendering Equation

The rendering equation describes the light emitted from each point in a scene according to the rules of geometric optics and can be written as follows:

$`L_s(x, \omega) = E(x, \omega) + \int_\Omega f_r(x,\omega^\prime, \omega) L_i(x,\omega^\prime) \cos (\theta) d\omega^\prime`$

Explain briefly the meaning of the following variables. (6 Points)

1. $`L_s(x, \omega)`$ : Light from x in direction $`\omega`$.
2. $`E(x, \omega)`$ : Light emission (if light source).
3. $`\Omega`$: Light from all other places in the scene.
4. $`f_r(x,\omega^\prime, \omega)`$: Reflection of object.
5. $`L_i(x, \omega^\prime)`$ : Light coming from direction $`\omega`$`.
6. $`\cos (\theta)`$: Attenuation if the light comes from the side.

### 1.2. Raytracing vs Radiosity

Name at least three difference between Raytracing and Radiosity. (2 Points).

1. Raytracing is very good at simulating specular reflections and transparency, since rays easily bounce from mirrors and refract by transparent objects in the scene, unlike radiosity.
2. The starting point of Raytracing is following all rays, when Radiosity simulates the diffuse propagation.
3. Radiosity is view independant, therefore the calculations have to only be performed once for the scene, this makes it possible to run radiosity real-time much easier than with raytracing.
