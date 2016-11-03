## 编程论语 EPIGRAMS IN PROGRAMMING 
作者： [Alan J. Perlis艾伦·佩利，1966年图灵奖](https://en.wikipedia.org/wiki/Alan_Perlis)

> 作为一个长者，我有必要给你们传授一点人生的经验。—— 长者


1. One man's constant is another man's variable. 一个人的常量是另一个人的变量。

2. Functions delay binding; data structures induce binding. Moral: Structure data late in the programming process.函数推迟了绑定，数据结构引发了绑定。寓意：编程时先考虑函数后考虑数据结构。

3. Syntactic sugar causes cancer of the semicolon.（在函数式程序中，）语法糖会导致分号癌症。

4. Every program is a part of some other program and rarely fits.每个程序（从功能上讲）都可以作为其它程序的一部分，但是（从接口上讲）却难以组合到其它程序中。

5. If a program manipulates a large amount of data, it does so in a small number of ways.如果一个程序要处理某种数据，在数据很少时，程序中包含了几种方法；当数据很大时，程序中包含的方法还是这么多。

6. Symmetry is a complexity-reducing concept (co-routines include subroutines); seek it everywhere. 具有对称性意味着可以降低复杂度（协作的程序可能包含潜在的共同子程序）；要尝试在每个地方寻找这种对称性。

7. It is easier to write an incorrect program than understand a correct one.看懂一个正确的程序比写一个错误的程序要难。

8. A programming language is low level when its programs require attention to the irrelevant. 用一个语言写程序时，我们说这个编程语言比较接近底层，往往是因为这个语言需要过多地关注无关的事物。

9. It is better to have 100 functions operate on one data structure than 10 functions on 10 data structures.写一个程序，使用10个函数、10种数据结构，不如使用100个函数、一种数据结构。

10. Get into a rut early: Do the same process the same way. Accumulate idioms. Standardize. The only difference(!) between Shakespeare and you was the size of his idiom list - not the size of his vocabulary.早点进入轨道：同样的东西用同样的处理方式。积累习语。标准化。你和莎士比亚唯一的区别不是词汇量的差别，而是习语量的差别。

11. If you have a procedure with ten parameters, you probably missed some.如果你设计了一个带有10个参数的函数，那么你可能还是忘记了某些要加的参数。

12. **Recursion is the root of computation since it trades description for time.递归体现了计算的本质：用（精巧的）描述来换取时间（的节约）。**

13. If two people write exactly the same program, each should be put into microcode and then they certainly won't be the same.

14. In the long run every program becomes rococo - then rubble.长期地来讲，任何代码都会过时，最终被废弃。

15. Everything should be built top-down, except the first time.所有的系统都应该采用自顶向下的方式来开发，只有那些之前没有被开发过的系统是例外。

16. Every program has (at least) two purposes: the one for which it was written, and another for which it wasn't.所有程序的诞生都至少有两个原因：一个原因是它需要被用来解决某个问题，另一个原因是因为某种问题它还没被人写过。

17. **If a listener nods his head when you're explaining your program, wake him up.给一个人讲解你写的程序时，如果他频频点头，请把他叫醒。**

18. A program without a loop and a structured variable isn't worth writing.一个没有循环、没有复合数据结构的程序时不值得写的。

19. A language that doesn't affect the way you think about programming, is not worth knowing.一个不能影响你思考方式的编程语言是不值得学习的。

20. **Wherever there is modularity there is the potential for misunderstanding: Hiding information implies a need to check communication.模块化的地方就是误解产生的地方；信息隐藏的代价是需要检查通信的正确性。**

21. Optimization hinders evolution.优化阻碍了进化。（优化一般会使得代码难以理解，变得复杂，导致难以修改，所以不建议过度优化或者过早优化）

22. A good system can't have a weak command language.命令行不好的系统不是好系统。

23. **To understand a program you must become both the machine and the program.为了理解程序，你既要变成程序，又要变成机器。**

24. Perhaps if we wrote programs from childhood on, as adults we'd be able to read them.如果我们从小时候就开始写程序的话...那么成年了我们应该就看不懂那时写的代码了。

25. One can only display complex information in the mind. Like seeing, movement or flow or alteration of view is more important than the static picture, no matter how lovely.

26. There will always be things we wish to say in our programs that in all known languages can only be said poorly.总会存在某些我们想在程序中描述的东西，使用现有的编程语言不能很好的表达。

27. Once you understand how to write a program get someone else to write it.一旦你理解了如何去写一个程序，就让其他人来完成这个程序吧。

28. Around computers it is difficult to find the correct unit of time to measure progress. Some cathedrals took a century to complete. Can you imagine the grandeur and scope of a program that would take as long?对于程序，找到一个估计进度的时间单位是困难的。说一个教堂花费了上百年时间建成，人们会猜想这个教堂肯定很壮丽和宏伟。但是如果说一个程序花了上百年写完，人们恐怕不会有类似的感觉。

29. For systems, the analogue of a face-lift is to add to the control graph an edge that creates a cycle, not just an additional node.

30. **In programming, everything we do is a special case of something more general -- and often we know it too quickly.**

31. **Simplicity does not precede complexity, but follows it.程序的开发的过程中，先体现出复杂性，然后才体现出简洁性。**

32. Programmers are not to be measured by their ingenuity and their logic but by the completeness of their case analysis.对程序员来说，思考的完整性要比聪明和思考逻辑性更重要。

33. The eleventh commandment was "Thou Shalt Compute" or "Thou Shalt Not Compute" - I forget which.

34. The string is a stark data structure and everywhere it is passed there is much duplication of process. It is a perfect vehicle for hiding information.

35. Everyone can be taught to sculpt: Michelangelo would have had to be taught not to. So it is with great programmers.

36. The use of a program to prove the 4-color theorem will not change mathematics - it merely demonstrates that the theorem, a challenge for a century, is probably not important to mathematics.使用计算机程序来证明四色问题对数学本身没有什么贡献，它只是证明了这个百年未解的数学难题实际上对数学本身来说是不重要的。

37. The most important computer is the one that rages in our skulls and ever seeks that satisfactory external emulator. The standarization of real computers would be a disaster - and so it probably won't happen.

38. Structured Programming supports the law of the excluded middle.

39. Re graphics: A picture is worth 10K words - but only those to describe the picture. Hardly any sets of 10K words can be adequately described with pictures.

40. There are two ways to write error-free programs; only the third one works.有两种写出无bug程序的方法，但只有第三种方法是可以完成程序的。

41. Some programming languages manage to absorb change, but withstand progress.一些编程语言不停努力的改变，但却拒绝进步。

42. You can measure a programmer's perspective by noting his attitude on the continuing vitality of FORTRAN.

43. **In software systems, it is often the early bird that makes the worm.在软件开发中，往往是早起的鸟儿制造了虫子。**

44. Sometimes I think the only universal in the computing field is the fetch-execute cycle.

45. The goal of computation is the emulation of our synthetic abilities, not the understanding of our analytic ones.

46. Like punning, programming is a play on words.

47. As Will Rogers would have said, "There is no such thing as a free variable."

48. The best book on programming for the layman is "Alice in Wonderland"; but that's because it's the best book on anything for the layman.对门外汉来说，最好的编程书籍是《爱丽丝梦游仙境》。因为不管是什么领域，只要是门外汉，这本书都是最好的。

49. Giving up on assembly language was the apple in our Garden of Eden: Languages whose use squanders machine cycles are sinful. The LISP machine now permits LISP programmers to abandon bra and fig-leaf.

50. When we understand knowledge-based systems, it will be as before -- except our fingertips will have been singed.

51. Bringing computers into the home won't change either one, but may revitalize the corner saloon.

52. Systems have sub-systems and sub-systems have sub- systems and so on ad infinitum - which is why we're always starting over.

53. So many good ideas are never heard from again once they embark in a voyage on the semantic gulf.

54. Beware of the Turing tar-pit in which everything is possible but nothing of interest is easy.

55. **A LISP programmer knows the value of everything, but the cost of nothing.一个Lisp程序员知道程序中所有东西的值，但是不知道这些东西的代价。**

56. Software is under a constant tension. Being symbolic it is arbitrarily perfectible; but also it is arbitrarily changeable.

57. It is easier to change the specification to fit the program than vice versa.

58. **Fools ignore complexity. Pragmatists suffer it. Some can avoid it. Geniuses remove it.对于问题的复杂性，傻瓜程序员没有意识到它，急躁的程序员深陷于它，有些程序员试图逃避它，天才的程序员消灭它。**

59. In English every word can be verbed. Would that it were so in our programming languages.

60. In seeking the unattainable, simplicity only gets in the way.

61. In programming, as in everything else, to be in error is to be reborn.

62. In computing, invariants are ephemeral.

63. **When we write programs that "learn", it turns out that we do and they don't.当我们写能够学习的程序时，我们学到了很多，但程序什么也没学到。**

64. Often it is the means that justify the ends: Goals advance technique and technique survives even when goal structures crumble.

65. Make no mistake about it: Computers process numbers - not symbols. We measure our understanding (and control) by the extent to which we can arithmetize an activity.

66. Making something variable is easy. Controlling duration of constancy is the trick.

67. Think of all the psychic energy expended in seeking a fundamental distinction between "algorithm" and "program".

68. If we believe in data structures, we must believe in independent (hence simultaneous) processing. For why else would we collect items within a structure? Why do we tolerate languages that give us the one without the other?

69. In a 5 year period we get one superb programming language. Only we can't control when the 5 year period will be.

70. Over the centuries the Indians developed sign language for communicating phenomena of interest. Programmers from different tribes (FORTRAN, LISP, ALGOL, SNOBOL, etc.) could use one that doesn't require them to carry a blackboard on their ponies.

71. Documentation is like term insurance: It satisfies because almost no one who subscribes to it depends on its benefits.

72. An adequate bootstrap is a contradiction in terms.

73. It is not a language's weakness but its strengths that control the gradient of its change: Alas, a language never escapes its embryonic sac.

74. Is it possible that software is not like anything else, that it is meant to be discarded: that the whole point is to see it as a soap bubble?

75. Because of its vitality, the computing field is always in desperate need of new cliches: Banality soothes our nerves.

76. It is the user who should parameterize procedures, not their creators.

77. The cybernetic exchange between man, computer and algorithm is like a game of musical chairs: The frantic search for balance always leaves one of the three standing ill at ease.

78. If your computer speaks English, it was probably made in Japan.

79. **A year spent in artificial intelligence is enough to make one believe in God.在人工智能领域待上一年，就足够让人开始相信上帝的存在了。**

80. Prolonged contact with the computer turns mathematicians into clerks and vice versa.

81. **In computing, turning the obvious into the useful is a living definition of the word "frustration".在计算机领域，把“显而易见的东西”变成“能用的东西”的过程，简直是对“挫折”最生动的定义。**

82. We are on the verge: Today our program proved Fermat's next-to-last theorem.

83. What is the difference between a Turing machine and the modern computer? It's the same as that between Hillary's ascent of Everest and the establishment of a Hilton hotel on its peak.

84. **Motto for a research laboratory: What we work on today, others will first think of tomorrow.适合研究型实验室的格言：我们今天做的东西，其他人明天才能第一次想到。**

85. Though the Chinese should adore APL, it's FORTRAN they put their money on.

86. We kid ourselves if we think that the ratio of procedure to data in an active data-base system can be made arbitrarily small or even kept small.

87. We have the mini and the micro computer. In what semantic niche would the pico computer fall?

88. It is not the computer's fault that Maxwell's equations are not adequate to design the electric motor.

89. One does not learn computing by using a hand calculator, but one can forget arithmetic.

90. Computation has made the tree flower.

91. The computer reminds one of Lon Chaney -- it is the machine of a thousand faces.

92. The computer is the ultimate polluter: its feces are indistinguish- able from the food it produces.

93. **When someone says "I want a programming language in which I need only say what I wish done," give him a lollipop.一个人说他想要一个编程语言：“只要告诉编程语言你想要什么，编程语言就帮你实现了”。如果你遇到这么一个人，请给他一个棒棒糖。**

94. Interfaces keep things tidy, but don't accelerate growth: Functions do.

95. **Don't have good ideas if you aren't willing to be responsible for them.不要说你拥有一个好想法，除非你准备对它负责。**

96. Computers don't introduce order anywhere as much as they expose opportunities.

97. When a professor insists computer science is X but not Y, have compassion for his graduate students.

98. In computing, the mean time to failure keeps getting shorter.

99. In man-machine symbiosis, it is man who must adjust: The machines can't.

100. We will never run out of things to program as long as there is a single program around.

101. **Dealing with failure is easy: Work hard to improve. Success is also easy to handle: You've solved the wrong problem. Work hard to improve.处理失败的方法很简单：努力工作去继续提高。处理成功的方法也很简单：你可能选错了问题，努力工作去选择新的问题。（意思是你已经成功解决的问题其实不是你应该做的问题么？！）**

102. One can't proceed from the informal to the formal by formal means.

103. Purely applicative languages are poorly applicable.

104. The proof of a system's value is its existence.

105. **You can't communicate complexity, only an awareness of it.你没法精确描述复杂性，只是知道它的存在。**

106. It's difficult to extract sense from strings, but they're the only communication coin we can count on.

107. The debate rages on: is PL/I Bachtrian or Dromedary?

108. **Whenever two programmers meet to criticize their programs, both are silent.**

109. Think of it! With VLSI we can pack 100 ENIACS in 1 sq. cm.

110. Editing is a rewording activity.

111. Why did the Roman Empire collapse? What is Latin for office automation?

112. **Computer Science is embarrassed by the computer.计算机科学因为计算机而感到难为情。**

113. **The only constructive theory connecting neuroscience and psychology will arise from the study of software.想要联系心理学和神经科学，唯一有建设性的理论将会来自对软件的研究。**

114. **Within a computer natural language is unnatural.对于计算机来说，自然语言是不自然的。**

115. **Most people find the concept of programming obvious, but the doing impossible.大部分人觉得编程的概念是显而易见的，结果发现动起手来却很困难。**

116. **You think you know when you can learn, are more sure when you can write, even more when you can teach, but certain when you can program.对于一个事物，你学了一下会觉得懂了，写下来之后会觉得又懂了一点，教给别人后会觉得更懂了，但是能写出程序后才会确定自己懂了。**

117. **It goes against the grain of modern education to teach children to program. What fun is there in making plans, acquiring discipline in organizing thoughts, devoting attention to detail and learning to be self-critical?**

118. If you can imagine a society in which the computer- robot is the only menial, you can imagine anything.

119. Programming is an unnatural act.编程是一种不自然的行为。

120. Adapting old programs to fit new machines usually means adapting new machines to behave like old ones.将旧的程序移植到新的机器上，往往意味着让新的机器按照旧机器的方式来解决问题。

> From ACM's SIGPLAN publication, (September, 1982), Article "Epigrams in Programming", by Alan J. Perlis of Yale University.http://www.cs.yale.edu/homes/perlis-alan/quotes.html
