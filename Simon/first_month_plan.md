## Project planing for the first month(s)

The project is centered around the simulation of NeuLAND detector and applying cuts on the simulated data to eliminate the unwanted high energy deposition. However, in the first few months, you should focus more on the basic aspects and tools, such as Unix system, git (Github), C++ and the simulation framework of [R3BRoot](https://github.com/R3BRootGroup/R3BRoot). Most of the things you will do later relies heavily on how well you understand the those tools and frameworks. But don't worry. I introduce them to you little by little throughout these weeks. Here are some more detailed plans I have in my mind **INITIALLY**:

- Week 1: **Unix system, Git(hub) and "Hello world"**

    We will start with the most basic things in the first week, like how to navigate in the terminal (see [this tutorial from our institute](../linux)) and how to write a C++ "Hello world" (Using CMake as the build system). I'm not sure how much you've learned before or during last few weeks. But if you already knew some of them, that's great and we can move faster. An IDE is also very important. For the most of the time, we are going to work inside a server and the modern IDEs may not work very well in this case. Therefore, (if you want) I will also teach you some basic configurations and usage about [NeoVim](https://github.com/neovim/neovim).


- Week 2\~4: **OOP, C++ and CMake**
  
    These weeks we will dive into C++ and OOP world. Again, we will only discuss the basic ones and I hope you will learn more advanced ones little by little in the coming years. 

    The basic ones for OOP are mainly:

    * [ ] What the class and object are and what the public, private and protected interfaces and properties are.
    * [ ] What inheritance and polymorphism are.
    * [ ] What abstract class is.
    * [ ] static inheritance (template) vs. dynamic inheritance.

    These things are not unique to C++ and you could also find them in other popular programming langauges like Java or C#.

    The basic ones for C++ are mainly:

    * [ ] What header files and source files are.
    * [ ] What libraries (static and dynamic) are.
    * [ ] stack and heap.
    * [ ] STL Containers (`std::vector`, `std::map`, etc).
    * [ ] Memory ownership (`std::unique_ptr`).
    * [ ] Many best practices we should follow.
    * [ ] How to debug (GDB).

    The basic ones for CMake are mainly:

    * [ ] CMake targets.
    * [ ] to create executable and library.
    * [ ] Project tree structure.
    
    These three aspects I listed above are kind of intertwined and dependent on each other. So we will not go through them one by one in order but rather bring them together.
    
- Week 4\~5: **Your "first histogram"**

    After a few weeks of learning C++, we could move to those frameworks that are crucial to your project: namely ROOT and R3BRoot. They are both very large C++ libraries created decades ago. Therefore, they do not comply with modern C++ standard and generally are not good practices.
    The main purpose we use ROOT is for data storage (`.root` file) and data visualization (if you mind the beauty of plots, you should use Python). From the R3BRoot, I will show you how to generate your first simulated data and store them into root files. And then from the root files, you will learn how to plot some values from the data inside using R3BRoot.

> [!Warning]
> ROOT contains a lot of custom data types used by many people in physics community. Most of them are **AWFUL** and please ignore them. Instead, you should use STL data types provided by C++ standard committee.
