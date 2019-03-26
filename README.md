
ECDH是EC是"elliptic curves"的意思，DH是"Diffie-Hellman"的意思。它实际上是密钥协商算法，而不是加解密算法。
------
该算法可以用来解决如下问题：

在公网通道上如何进行安全的秘钥分派。
两端（Alice 和 Bob）想要安全的交换信息并且第三方不能获取到该信息。当然这也是TLS协议中的目的之一，举个例子。（其实下面的描述其实是ECDHE,而不是ECDH）

Alice 和 Bob 生成他们自己的私钥和公钥，即Alice 有 da、Ha = da*G；Bob有db、Hb = db *G。

Alice把Ha发给Bob，Bob把Hb发给Alice。这样Alice 有da,Ha,Hb，Bob有db,Ha,Hb。

Alice计算S = daHb（即自己的私钥乘上Bob的公钥），同样的，Bob计算S = dbGa（自己的私钥乘上Alice的公钥）。两边计算的S是相同的。

S = da*Hb = da (db G) = db *(da *G) = db*Hb 等式1
中间人只知道到Ha和Hb，无法计算出共享密钥S。即离散对数问题为：中间人要计算 S，必须通过上述 等式1 中的一个等式来计算。显然必须知道da或者db，而中间人只知道Ha和Hb，即中间人为了获得da或者db需要从H或Hb中分离出da或db，显然这就是之前所说的离散对数问题。

现在Alice和Bob得到了共享密钥，后续可以使用共享密钥进行对称加密进行数据传输。通常情况下，点S中x向量被作为共享密钥。

例子
我们现在给出一个例子，设椭圆曲线为secp256k1（在SECG中被定义），它的
参数如下：



Alice的私钥（随机数）:

0xe32868331fa8ef0138de0de85478346aec5e3912b6029ae71691c384237a3eeb
Alice的公钥（由Alice的随机数乘上基点）:

(0x86b1aa5120f079594348c67647679e7ac4c365b2c01330db782b0ba611c1d677, 0x5f4376a23eed633657a90f385ba21068ed7e29859a7fab09e953cc5b3e89beba)
Bob的私钥（随机数）:

0xcef147652aa90162e1fff9cf07f2605ea05529ca215a04350a98ecc24aa34342
Bob的公钥（由Bob的随机数乘上基点）:

(0x4034127647bb7fdab7f1526c7d10be8b28174e2bba35b06ffd8a26fc2c20134a, 0x9e773199edc1ea792b150270ea3317689286c9fe239dd5b9c5cfd9e81b4b632)
双方得到的共享密钥:

(0x3e2ffbc3aa8a2836c1689e55cd169ba638b58a3a18803fcf7de153525b28c3cd, 0x43ca148c92af58ebdb525542488a4fe6397809200fe8c61b41a105449507083)
总结：
粗暴的理解记忆是，Alice和Bob协商着把共享密钥算了出来。

