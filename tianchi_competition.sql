--特征工程

--按秒统计的特征
drop table if exists portscan_feature_ss_test;
create table if not exists  portscan_feature_ss_test as 
select client_port,source_ip,ds,
count(distinct client_ip) as sip_client_ip_dn_cnt, --连接云主机类别数
sum(counts) as  sip_connect_n, --总连接次数
max(counts) as   sip_connect_n_max,--10秒内最大连接次数
avg(counts) as   sip_connect_n_avg,--10秒内平均连接次数
count(distinct hashuserid) as sip_hashuserid_dn --全天连接云主机拥有者个数
from kinsang_portscan_testset_connect_part2 group by client_port,source_ip,ds
;

--按分钟统计的特征
drop table if exists portscan_feature_mi_test_0;
create table if not exists portscan_feature_mi_test_0 as 
select client_port, source_ip, ds, hh, mi, 
sum(counts) as mi_counts, -- 一分钟的连数
count(distinct client_ip) as sip_client_ip_dn_cnt_per_mi, --某分钟连接云主机类别数
count(distinct hashuserid) as sip_hashuserid_dn_per_mi --某分钟连接云主机拥有者个数
from kinsang_portscan_testset_connect_part2
group by client_port, source_ip, ds, hh, mi;

drop table if exists portscan_feature_mi_test;
create table if not exists portscan_feature_mi_test as 
select client_port, source_ip, ds, 
max(sip_client_ip_dn_cnt_per_mi) as sip_client_ip_dn_cnt_max_per_mi,
avg(sip_client_ip_dn_cnt_per_mi) as sip_client_ip_dn_cnt_avg_per_mi,
max(sip_hashuserid_dn_per_mi) as sip_hashuserid_dn_max_per_mi,
avg(sip_hashuserid_dn_per_mi) as sip_hashuserid_dn_avg_per_mi,
max(mi_counts) as mi_max,  -- 分钟峰值
avg(mi_counts) as mi_avg, -- 分钟平均值
count(mi) as mi_freq  -- 分钟频数
from portscan_feature_mi_test_0 group by client_port, source_ip, ds
;

 --按小时统计的特征
 drop table  if exists  portscan_feature_hr_test_0;
create table if not exists portscan_feature_hr_test_0 as
select client_port, source_ip, ds, hh,
sum(counts) as hr_counts, 
count(distinct client_ip) as sip_client_ip_dn_cnt_per_hr, --某小时连接云主机类别数
count(distinct hashuserid) as sip_hashuserid_dn_per_hr --某小时连接云主机拥有者个数
from kinsang_portscan_testset_connect_part2
group by client_port, source_ip, ds, hh;

drop table if exists portscan_feature_hr_test;
create table if not exists portscan_feature_hr_test as
select client_port, source_ip, ds, 
max(sip_client_ip_dn_cnt_per_hr) as sip_client_ip_dn_cnt_max_per_hr,
avg(sip_client_ip_dn_cnt_per_hr) as sip_client_ip_dn_cnt_avg_per_hr,
max(sip_hashuserid_dn_per_hr) as sip_hashuserid_dn_max_per_hr ,
avg(sip_hashuserid_dn_per_hr) as sip_hashuserid_dn_avg_per_hr,
max(hr_counts) as hr_max,
avg(hr_counts) as hr_avg,
count(hh) as hr_freq
from portscan_feature_hr_test_0 group by client_port, source_ip, ds;

-- 拼表
drop table if exists portscan_feature_join_test_0;
create table if not exists  portscan_feature_join_test_0 as 
select a.*, 
b.sip_client_ip_dn_cnt_max_per_mi,
b.sip_client_ip_dn_cnt_avg_per_mi,
b.sip_hashuserid_dn_max_per_mi,
b.sip_hashuserid_dn_avg_per_mi,
b.mi_max,  -- 分钟峰值
b.mi_avg, -- 分钟平均值
b.mi_freq  -- 分钟频数
from portscan_feature_ss_test a 
left outer join portscan_feature_mi_test b 
on a.client_port=b.client_port and a.source_ip=b.source_ip and a.ds=b.ds;

drop table if exists portscan_feature_join_test_1;
create table if not exists  portscan_feature_join_test_1 as 
select a.*,
b.sip_client_ip_dn_cnt_max_per_hr,
b.sip_client_ip_dn_cnt_avg_per_hr,
b.sip_hashuserid_dn_max_per_hr ,
b.sip_hashuserid_dn_avg_per_hr,
b.hr_max,
b.hr_avg,
b.hr_freq
from portscan_feature_join_test_0 a 
left outer join portscan_feature_hr_test b 
on a.client_port=b.client_port and a.source_ip=b.source_ip and a.ds=b.ds;

-- 组合特征
drop table if exists portscan_feature_join_test_2;
create table if not exists  portscan_feature_join_test_2 as 
select *,
(sip_connect_n * 1.000 / hr_max / hr_freq) as links_div_hr_freq,
(hr_max * hr_freq  * 1.000 / sip_connect_n) as hr_mult_freq_div_links,
(sip_connect_n * 1.000 / hr_max) as hr_min_freq
from portscan_feature_join_test_1
