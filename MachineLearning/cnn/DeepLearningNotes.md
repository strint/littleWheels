* 神经网络中调节参数的原理是梯度下降
 * 负梯度方向是损失函数下降最快的方向
* 梯度下降需要计算损失函数对每个参数的偏导
* 导数在网络结构中具有前向传播、后向传播的性质，[参见Calculus on Computational Graphs: Backpropagation by Christopher Olah](http://colah.github.io/posts/2015-08-Backprop/)
 * 前向传播：某个变量的变化对后面与之关联的每个变量的的变化的影响
 * 后向传播：前面某个变量的的倒数可以用后面某个变量的导师间接求得（全倒数公式和链式法则）
 * 前向传播解释了前面某个变量对之后节点的影响
 * 后向传播提供了一种快速求解导数的方法
 * 后向传播算法的计算效率的提升可以用算法中的Dynamic Programming来解释，即后向传播算法是一种DP算法
 * 为什么BP算法思路并不难，单是却发现的比较晚？神经网络因为没有很好的求解方法，所以被认为是不实用；然后因为被认为是不实用的所以就没有人去研究好的求解方法。这产生了一种循环依赖，一种死循环，导致研究没有进展。
* 全倒数公式和链式法则：连线相乘, 分叉相加, 单路全导, 叉路偏导，[参见课件](http://wenku.baidu.com/link?url=FNI0M1MZnXS4_z3DieE4wXrmWEUVA8th2HvkalN98JvXq7quG3KQrnipNQlxC6syTIrWsjnLOR7YvjU5J05uHWzMG11K92D21eQo68QhA0W)



