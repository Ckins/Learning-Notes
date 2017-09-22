select elements in table A, which also appear in table B.

```sql
select from A where A.name in (select B.name from B);
```

```sql
select from B where not exists(select * from A where A.id=B.id and A.name=B.name)
```
left outer join, right outer join and inner join.
