#计算系统的设计原则
## 适用于各种计算系统的设计原则
* 彻底的简化（simpliﬁcations）
这样你就能看懂你在做什么

* 避免过度的泛化（generality）
如果它适用于任何情况，那么它对任何情况又都不那么适用了

* 避免使用那些不常用的组件（components）
组件一旦不被使用，它的代码就开始退化和腐烂（deterioration and corruption）

* 明确（explicit）
明确说明所有的假设

* 使用间接（indirection）的方法来分解模块
间接的方法使得模块具有可替换性（replaceability）

* 方便迭代（iteration）
一次成功很难，所以让它容易修改

* 端对端的论证（end-to-end argument）
系统的使用者最了解系统的好坏

* 不断上升的复杂度定律（complexity）
添加一个特性（feature）会增加系统的复杂度

* 放大（scaling）不成比例定律
把一个参数扩大十倍可能需要全新的设计才能达到

* 不断挖掘原因（keep digging）
复杂的系统因为复杂的原因而运行失败

* 收益递减（diminishing returns）规律
只不断改进某一部分，而不考虑改进其它部分，总的提升的增量即边际收益将会出现递减现象

* 公开设计（open design）
让其他人能够评价设计，所有的帮助都是必要的

* 最小惊讶（least astonishment）
用户是系统的一部分，提供的接口要符合用户经历、预期和思考方式

* 健壮性（robustness）
能容忍各种输入，但严格控制输出

* 安全距离（safety margin）
和危险保持安全距离

* 基础结构的顽固性
修改模块的内部容易，但是修改模块的划分很难

## 适用于特定计算系统的的设计原则
* 原子性：原子性中的黄金法则
不要修改唯一的一份拷贝！

* 协调性：一个写者原则
如果每个变量只有一个写者，协调就会变得简单

* 持久性：持久性的秘诀
多备份，远距离分布，独立管理

* 安全性：使得保密内容尽量少
因为保密内容不可能永远保密

* 安全性：彻底的裁定
检查每一个操作的真实性、完整性和权限

* 安全性：使用默认（default）操作来保障失败时的安全（Fail-safe）
大部分用户并不做修改，所以可以设置默认的安全操作

* 安全性：最小权限原则
不要把午餐和珠宝一样放在保险箱里

* 安全性：机制的经济学
机制越少，越可能正确的实施

* 安全性：最小化共同机制
共享机制提供了意外的通信途径

## 设计提示（很有用，但是不具有设计原则那样的强制性）
* 使用暴力解法（brute force）

* 减少延迟的方法之一是隐藏延迟

* 针对高频的部分去做优化

* 把机制同策略分离


# Design principles of computer systems
## Design principles applicable to many areas of computer systems
* Adopt sweeping simpliﬁcations 
So you can see what you are doing. 

* Avoid excessive generality 
If it is good for everything, it is good for nothing. 

* Avoid rarely used components 
Deterioration and corruption accumulate unnoticed—until the next use. 

* Be explicit 
Get all of the assumptions out on the table. 

* Decouple modules with indirection 
Indirection supports replaceability. 

* Design for iteration 
You won't get it right the first time, so make it easy to change. 

* End-to-end argument 
The application knows best. 

* Escalating complexity principle 
Adding a feature increases complexity out of proportion. 

* Incommensurate scaling rule 
Changing a parameter by a factor of ten requires a new design.

* Keep digging principle 
Complex systems fail for complex reasons. 

* Law of diminishing returns 
The more one improves some measure of goodness, the more effort the next improvement will require. 

* Open design principle 
Let anyone comment on the design; you need all the help you can get. 

* Principle of least astonishment 
People are part of the system. Choose interfaces that match the user’s experience, expectations, and mental models. 

* Robustness principle 
Be tolerant of inputs, strict on outputs. 

* Safety margin principle 
Keep track of the distance to the edge of the cliff or you may fall over the edge. 

* Unyielding foundations rule 
It is easier to change a module than to change the modularity. 

## Design principles applicable to speciﬁc areas of computer systems 
* Atomicity: Golden rule of atomicity 
Never modify the only copy! 

* Coordination: One-writer principle 
If each variable has only one writer, coordination is simpler. 

* Durability: The durability mantra 
Multiple copies, widely separated and independently administered.

* Security: Minimize secrets 
Because they probably won’t remain secret for long. 

* Security: Complete mediation 
Check every operation for authenticity, integrity, and authorization. 

* Security: Fail-safe defaults 
Most users won’t change them, so set defaults to do something safe. 

* Security: Least privilege principle 
Don’t store lunch in the safe with the jewels. 

* Security: Economy of mechanism 
The less there is, the more likely you will get it right. 

* Security: Minimize common mechanism 
Shared mechanisms provide unwanted communication paths. 

## Design Hints (useful but not as compelling as design principles)
* Exploit brute force 

* Instead of reducing latency, hide it

* Optimize for the common case

* Separate mechanism from policy 


http://ocw.mit.edu/resources/res-6-004-principles-of-computer-system-design-an-introduction-spring-2009/online-textbook/
