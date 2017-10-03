--模型预测
drop table if exists portscan_pre_result_sample_v3;
PAI -name prediction -project algo_public -DdetailColName="prediction_detail" -DappendColNames="client_port,source_ip,ds" 
-DmodelName="GBDT_test_model_sample_v3" 
-DitemDelimiter="," -DresultColName="prediction_result" -Dlifecycle="28" 
-DoutputTableName="portscan_pre_result_sample_v3" 
-DscoreColName="prediction_score" -DkvDelimiter=":" 
-DfeatureColNames="sip_client_ip_dn_cnt,sip_connect_n,sip_connect_n_max,sip_hashuserid_dn,sip_connect_n_avg,sip_client_ip_dn_cnt_max_per_mi,sip_client_ip_dn_cnt_avg_per_mi,sip_hashuserid_dn_max_per_mi,sip_hashuserid_dn_avg_per_mi,mi_max,mi_avg,mi_freq,sip_client_ip_dn_cnt_max_per_hr,sip_client_ip_dn_cnt_avg_per_hr,sip_hashuserid_dn_max_per_hr,sip_hashuserid_dn_avg_per_hr,hr_max,hr_avg,hr_freq,links_div_hr_freq,hr_mult_freq_div_links,hr_min_freq"
-DinputTableName="portscan_train_0625_0701"
-DenableSparse="false";

--生成提交答案
drop table if exists tianchi_portscan_answer_sample_v3;
create table if not exists tianchi_portscan_answer_sample_v3 as
select distinct client_port,source_ip,ds from portscan_pre_result_sample_v3 where prediction_result=1;
