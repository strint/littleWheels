#! /usr/bin/env python
# -*- coding=utf-8 -*-

import math

# 2010年中国各个年龄段人口分布，5年一段，按80年平均寿命，分成16段，统计数据中的80及以上的人数都归到第16段
people_num_at_age = [75532610, 70881549, 74908462, 99889114, 127412518, 101013852, 97138203, 118025959, \
                     124753964, 105594553, 78753171, 81312474, 58667282, 41113282, 32972397, \
                     23852133 + 13373198 + 5631928 + 1578307 + 369979 + 35934]
# 保存一份2010年的数据供最后做比较
people_num_at_age_before = [75532610, 70881549, 74908462, 99889114, 127412518, 101013852, 97138203, 118025959, \
                     124753964, 105594553, 78753171, 81312474, 58667282, 41113282, 32972397, \
                     23852133 + 13373198 + 5631928 + 1578307 + 369979 + 35934]
# 分段数
age_groups = len(people_num_at_age)

# 记录2010年的总人口数，初始化
total_number_before = 0
# 记录后来的总人口数，初始化
total_number = 0
# 记录离开地球的总人数，初始化
leave_earth = 0
# 记录来到地球的总人数，初始化
come_earth = 0

#输出2010年中国人口分布情况
print "2010年中国人口分布情况:\n"
for m in range(age_groups):
    total_number_before = total_number_before + people_num_at_age_before[m]
    print "年龄段在 %2d 和 %2d 之间的有%10d人.\n" % (m * 5, (m + 1) * 5 - 1, people_num_at_age_before[m])
print "2010年中国有 %d 人.\n" % total_number_before

# 输入
choose = int(raw_input("计算你生命周期类的人口预测，请输入1；计算未来x年的人口预测，请输入2。\n"))

# print choose

# n 作为时间输入，表示请求计算 n*5 年后的中国人口分布
if choose == 1 :
  # birth_year 作为出生时间输入
  birth_year = int(raw_input("请输入你出生的年号，如1990：\n"))
  diff = 2010 - birth_year
  # print diff
  age_stage = math.ceil(float(diff / 5.0))
  n = int(16 - age_stage)
  # print n
  print "2010年时你处于第%d年龄段。\n" % (age_stage)
  print "你的预计寿命(80岁)还有%d个年龄段。 \n" % (n)
else:
  year_long = int(raw_input("请输入你想计算的未来多少年人口预测，如100：\n"))
  n = int(math.ceil(float(year_long / 5.0)))
  # print n

# b 作为出生政策输入，表示实行 b 胎制
b = int(raw_input("请输入实施几胎制，如1，表示一胎制："))


# 计算
for i in range(n):
    # 来的地球的人
    new_baby = (people_num_at_age[5] / 2) * b
    come_earth = come_earth + new_baby

    #离开地球的人
    leave_earth = leave_earth + people_num_at_age[age_groups - 1]

    # 每个年龄段的人增加5岁，进入下一个年龄段；最后一个年龄段的人离开地球
    for j in range(age_groups): 
        people_num_at_age[age_groups - 1 - j] = people_num_at_age[age_groups - 1 - j -1]
    # 新生少儿进入第1年龄段
    people_num_at_age[0] = new_baby

    # 20至29之间的人：没有孩子，爸妈还未退休，主要在照顾自己；
    # 30至49之间的人，下有未成年的小孩，上有退休的父母；
    # 50至59之间的人：孩子已经成年，爸妈基本不在了，主要在照顾自己；

    # 记录没有进入工作年龄的人数，初始化
    young_peop = 0
    # 记录处在工作年龄的人数，初始化
    working_peop = 0
    # 记录处在30~49的、上有老下有小的人数，初始化
    working_peop_m = 0
    # 记录退休的老人的人数，初始化
    retired_peop = 0

    for peop_ratio_count_y in range(4):
      young_peop = young_peop + people_num_at_age[peop_ratio_count_y]
    for peop_ratio_count_w in range(4, 12):
      working_peop = working_peop + people_num_at_age[peop_ratio_count_w]
    for peop_ratio_count_wm in range(6, 10):
      working_peop_m = working_peop_m + people_num_at_age[peop_ratio_count_wm]
    for peop_ratio_count_r in range(12, 16):
      retired_peop = retired_peop + people_num_at_age[peop_ratio_count_r]

    working_to_young = float(working_peop) / float(young_peop)
    working_m_to_young = float(working_peop_m) / float(young_peop)
    retired_to_young = float(retired_peop) / float(young_peop)

    print "/5年过去了/ \n"
    if choose == 1:
      print "你处于第%d年龄段时：\n" % (age_stage + i + 1)

    print "时间处于 %d 年至 %d 年：\n" % (2010 + (i * 5), 2010 + ((i + 1) * 5) )
    print "未工作的孩子(0~19) ：上老下小的(30~49) ：退休的老人(60及以后) = %5.3f : %5.3f : %5.3f . \n" % \
    (1.000, working_m_to_young, retired_to_young)
    print "一对在30~49岁的夫妇要照顾的人数（小孩+老人）是：%5.3f.\n" % \
    ((retired_to_young + 1) / (working_m_to_young / 2))
    print "退休的老年人在人口中的比例是：百分之 %6.3f .\n" % ((retired_to_young / \
      (1 + working_to_young + retired_to_young)) * 100)






# 输出结果
print "%d 年后的中国人口分布 :\n" % (n * 5)
for k in range(age_groups):
    total_number = total_number + people_num_at_age[k]
    increase = float((people_num_at_age[k] - people_num_at_age_before[k])) / float(people_num_at_age_before[k])
    print "年龄段在 %2d 和 %2d 之间的有 %10d 人, 相对于2010年增加了 %6.3f 个百分比. \n" % (k * 5, (k + 1) * 5 - 1, people_num_at_age[k], increase * 100)

increase_total = float((total_number - total_number_before)) / float(total_number_before)
print "严格实行 %d 胎制，%d 年后, 中国将有 %d 人 , 相对于2010年增加了 %6.3f 个百分比. \n\n" % (b, n * 5, total_number, increase_total * 100)

print "  这 %d 年中，有约 %5.3f 亿中国人离开地球，又有约 %5.3f 亿个新人来到地球上的中国，结果是多了约 %5.3f 亿人，中国还有 %5.3f 亿人。\n " \
      % (n * 5, float(leave_earth) / 10**8, float(come_earth) / 10**8, float(come_earth - leave_earth) / 10**8, float(total_number) / 10**8)
    
