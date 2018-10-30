﻿using System;
using System.Collections.Generic;
using System.Linq;

namespace Heroius.XuAlgrithms.Utility
{
    /// <summary>
    /// 提供需求方法和算法名之间的映射
    /// </summary>
    public static class Mapping
    {
        /// <summary>
        /// 在所有定义的算法中查询功能包含关键字的算法类名
        /// </summary>
        /// <param name="keyword">关键字</param>
        /// <returns></returns>
        public static IEnumerable<string> Search(string keyword)
        {
            return ChsNames.Keys.Search(keyword);
        }
        /// <summary>
        /// 在已筛选的算法类名中进一步筛选
        /// </summary>
        /// <param name="collection">已经筛选的算法类名</param>
        /// <param name="keyword">筛选关键字</param>
        /// <returns></returns>
        public static IEnumerable<string> Search(this IEnumerable<string> collection, string keyword)
        {
            return collection.Where(key => ChsNames[key].Contains(keyword));
        }
        /// <summary>
        /// 获取全部定义的算法名
        /// </summary>
        /// <returns></returns>
        public static IEnumerable<string> GetAllAlgrithmNames()
        {
            return ChsNames.Keys.AsEnumerable();
        }

        /// <summary>
        /// 获取算法描述
        /// </summary>
        /// <param name="key">算法名</param>
        /// <returns></returns>
        public static string GetDescription(string key)
        {
            return ChsNames[key];
        }

        internal static readonly Dictionary<string, string> ChsNames = new Dictionary<string, string>() {
            //矩阵运算
            { "TRMUL", "实矩阵相乘" },
            { "TCMUL", "复矩阵相乘" },
            { "RINV", "一般实矩阵求逆" },
            { "CINV", "一般复矩阵求逆" },
            { "SSGJ", "对称正定矩阵求逆" },
            { "TRCH", "托伯利兹矩阵求逆的特兰持方法" },
            { "SDET", "求一般行列式的值" },
            { "RANK", "求矩阵的秩" },
            { "CHOL", "对称正定矩阵的乔里斯基分解与行列式求值" },
            { "LLUU", "矩阵的三角分解" },
            { "MAQR", "一般实矩阵的QR分解" },
            { "MUAV", "一般实矩阵的奇异值分解" },
            { "GINV", "求广义逆的奇异值分解法" },
            //矩阵特征值与特征向量的计算
            { "SSTQ", "求对称三对角阵的全部特征值与特征向量" },
            { "STRQ", "约化对称矩阵为对称三对角阵的豪斯荷尔德变换法" },
            { "HHBG", "约化一般实矩阵为赫申伯格矩阵的初等相似变换法" },
            { "HHQR", "求赫申伯格矩阵全部特征值的QR方法" },
            { "JCBI", "求实对称矩阵特征值与特征向量的雅可比法" },
            { "JCBJ", "求实对称矩阵特征值与特征向量的雅可比过关法" },
            //todo: BGQR in V4
            //线性代数方程组的求解
            { "GAUS", "求解实系数方程组的全选主元高斯消去法" },
            { "GJDN", "求解实系数方程组的全选主元高斯-约当消去法" },
            { "CGAS", "求解复系数方程组的全选主元高斯消去法" },
            { "CJDN", "求解复系数方程组的全选主元高斯-约当消去法" },
            { "TRDE", "求解三对角线方程组的追赶法" },
            { "BAND", "求解一般带型方程组" },
            { "LDLE", "求解对称方程组的分解法" },
            { "CHLK", "求解对称正定方程组的平方根法" },
            { "TLVS", "求解托伯利兹方程组的列文逊方法" },
            { "GSDL", "高斯-赛德尔迭代法" },
            { "GRAD", "求解对称正定方程组的共轭梯度法" },
            { "GMQR", "求解线性最小二乘问题的豪斯荷尔德变换法" },
            { "GMIV", "求解线性最小二乘问题的广义逆法" },
            { "BINT", "求解病态方程组" },
            //非线性方程与方程组的求解
            { "", "求非线性方程实根的对分法" },
            { "", "求非线性方程一个实根的牛顿法" },
            { "", "求非线性方程一个实根的埃特金迭代法" },
            { "", "求非线性方程一个实根的试位法" },
            { "", "求非线性方程一个实根的连分式法" },
            { "", "求实系数代数方程全部根的QR方法" },
            { "", "求实系数代数方程全部根的牛顿下山法" },
            { "", "求复系数代数方程全部根的牛顿下山法" },
            { "", "求非线性方程组一组实根的梯度法" },
            { "", "求非线性方程组一组实根的拟牛顿法" },
            { "", "求非线性方程组最小二乘解的广义逆法" },
            { "", "求非线性方程一个实根的蒙特卡罗法" },
            { "", "求实函数或复函数方程一个复根的蒙特卡罗法" },
            { "", "求非线性方程组一组实根的蒙特卡罗法" },
            //多项式计算
            { "", "一维多项式求值" },
            { "", "一维多项式多组求值" },
            { "", "二维多项式求值" },
            { "", "复系数多项式求值" },
            { "", "多项式相乘" },
            { "", "复系数多项式相乘" },
            { "", "多项式相除" },
            { "", "复系数多项式相除" },
            { "", "实系数多项式类" },
            { "", "复系数多项式类" },
            //复数运算
            { "", "复数乘法" },
            { "", "复数出发" },
            { "", "复数乘幂" },
            { "", "复数的n次方根" },
            { "", "复数指数" },
            { "", "复数对数" },
            { "", "复数正弦" },
            { "", "复数余弦" },
            { "", "复数类" },
            //随机数的产生
            { "", "产生0~1之间均匀分布的一个随机数" },
            { "", "产生0~1之间均匀分布的随机数序列" },
            { "", "产生任意区间内均匀分布的一个随机整数" },
            { "", "产生任意区间内均匀分布的随机整数序列" },
            { "", "产生任意均值与方差的正态分布的一个随机数" },
            { "", "产生任意均值与方差的正态分布的随机数序列" },
            //插值与逼近
            { "", "一元全区间插值" },
            { "", "一元三点插值" },
            { "", "连分式插值" },
            { "", "埃尔米特插值" },
            { "", "埃特金逐步插值" },
            { "", "光滑插值" },
            { "", "第一种边界条件的三次样条函数插值、微商与积分" },
            { "", "第二种边界条件的三次样条函数插值、微商与积分" },
            { "", "第三种边界条件的三次样条函数插值、微商与积分" },
            { "", "二元三点插值" },
            { "", "二元全区间插值" },
            { "", "最小二乘曲线拟合" },
            { "", "切比雪夫曲线拟合" },
            { "", "最佳一致逼近的里米兹方法" },
            { "", "矩形域的最小二乘曲面拟合" },
            //数值积分
            { "", "变步长梯形求积法" },
            { "", "变步长辛卜生求积法" },
            { "", "自适应梯形求积法" },
            { "", "龙贝格求积法" },
            { "", "计算一维积分的连分式法" },
            { "", "高振荡函数求积法" },
            { "", "勒让德-高斯求积法" },
            { "", "拉盖尔-高斯求积法" },
            { "", "埃尔米特-高斯求积法" },
            { "", "切比雪夫求积法" },
            { "", "计算一维积分的蒙特卡罗法" },
            { "", "变步长辛卜生二重积分法" },
            { "", "计算多重积分的高斯方法" },
            { "", "计算二重积分的连分式法" },
            { "", "计算多重积分的蒙特卡罗法" },
            //常微分方程组的求解
            { "", "全区间积分的定步长欧拉方法" },
            { "", "积分一步的变步长欧拉方法" },
            { "", "全区间积分的维梯方法" },
            { "", "全区间积分的定步长龙格-库塔方法" },
            { "", "积分一步的变步长龙格-库塔方法" },
            { "", "积分一步的变步长基尔方法" },
            { "", "全区间积分的变步长默森方法" },
            { "", "积分一步的连分式法" },
            { "", "全区间积分的双边法" },
            { "", "全区间积分的阿当姆斯预报校正法" },
            { "", "全区间积分的哈明方法" },
            { "", "积分一步的特雷纳方法" },
            { "", "积分刚性方程组的吉尔方法" },
            { "", "求解二阶微分方程边值问题的差分法" },
            //数据处理
            { "", "随机样本分析" },
            { "", "一元线性回归分析" },
            { "", "多元线性回归分析" },
            { "", "逐步回归分析" },
            { "", "半对数数据相关" },
            { "", "对数数据相关" },
            //极值问题的求解
            { "", "一维极值连分式法" },
            { "", "n维极值连分式法" },
            { "", "不等式约束线性规划问题" },
            { "", "求n维极值的单形调优法" },
            { "", "求约束条件下n维极值的复形调优法" },
            //数学变换与滤波
            { "", "傅里叶级数逼近" },
            { "", "快速傅里叶变换" },
            { "", "快速沃什变换" },
            { "", "五点三次平滑" },
            { "", "离散随机线性系统的卡尔曼滤波" },
            { "", "α-β-γ滤波" },
            //特殊函数的计算
            { "", "伽马函数" },
            { "", "不完全伽马函数" },
            { "", "误差函数" },
            { "", "第一类整数阶贝塞耳函数" },
            { "", "第二类整数阶贝塞耳函数" },
            { "", "变型第一类整数阶贝塞耳函数" },
            { "", "变型第二类整数阶贝塞耳函数" },
            { "", "不完全贝塔函数" },
            { "", "正态分布函数" },
            { "", "t-分布函数" },
            { "", "χ²-分布函数" },
            { "", "F-分布函数" },
            { "", "正弦积分" },
            { "", "余弦积分" },
            { "", "指数积分" },
            { "", "第一类椭圆积分" },
            { "", "第二类椭圆积分" },
            //排序
            { "", "冒泡排序" },
            { "", "快速排序" },
            { "", "希尔排序" },
            { "", "堆排序" },
            { "", "结构排序" },
            { "", "磁盘文件排序" },
            { "", "拓扑分类" },
            //查找
            { "", "结构体数组的顺序查找" },
            { "", "磁盘随机文本文件的顺序查找" },
            { "", "有序数组的对分查找" },
            { "", "按关键字成员有序的结构体数组的对分查找" },
            { "", "按关键字有序的磁盘随机文本文件的对分查找" },
            { "", "磁盘随机文本文件的字符串匹配" }
        };
    }
}
