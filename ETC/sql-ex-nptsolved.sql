----123

with a as(SELECT model, price FROM PC
UNION
SELECT model, price FROM Printer
UNION
SELECT model, price FROM Laptop),
b as(Select price from a group by price having count(model) > 1)

----127
with a1 as(Select maker From Product where model in (Select model from PC where cd = (Select min(cd) From PC))),
a2 as (Select distinct a1.maker maker, p.model model, price From a1
join Product p on p.maker = a1.maker
join Laptop l on p.model = l.model),
b1 as (Select maker From Product where model in (Select model from Printer where price = (Select min(price) From Printer))),
b2 as (Select distinct b1.maker maker, p.model model, price From b1
join Product p on p.maker = b1.maker
join PC l on p.model = l.model),
c1 as (Select maker From Product where model in (Select model from Laptop where ram = (Select max(ram) From Laptop))),
c2 as (Select distinct c1.maker maker, p.model model, price From c1
join Product p on p.maker = c1.maker
join Printer l on p.model = l.model)

Select convert(numeric(10,2),avg(price)) From(Select maker, price From a2 where price = (Select min(price) from a2)
union
Select maker, price From b2 where price = (Select max(price) from b2)
union
Select maker, price From c2 where price = (Select max(price) from c2))x

---132

with a as(Select convert(char(10),date, 120) date1,
convert(char(10), case 
when lead(date) over(order by date) is null then getdate() 
else lead(date) over(order by date) end, 120) date2
From Battles),
b as(Select
case 
when datepart(day, date1) > datepart(day, date2)
then datediff(month, date1, date2) - 1
else datediff(month, date1, date2)
end months,
date1, date2 
From a)
Select 
case
when months/12 > 0
then
(case
when months%12 = 0
then convert(varchar(2),months/12) + ' y.'
else convert(varchar(2),months/12) + ' y., ' + convert(varchar(2),months) + ' m.' 
end)
else convert(varchar(2),months) + ' m.' 
end age
date1,date2
from b

---139

with a as(Select name, launched From Ships where name not in (Select ship from Outcomes) and class not in (Select ship from Outcomes)), 
b as (Select a.name name, b.name battle, rank() over(partition by a.name order by date) rank From a, Battles b where launched > year(date)),
c as(Select a.name name, battle, rank from a left join b on b.name = a.name),
d as(Select name, list, len(list) l from(Select name,
case when battle is null then NULL else (select battle + ',' as 'data()' from c c2 where c1.name = c2.name order by rank for xml path('')) end list
From c c1) x)
Select distinct name, replace(substring(list, 0, len(list)), ', ' , ',') From d

----133

with a as(Select id_comp, i = 1 from company
Union all
Select id_comp, i + 1 from a where i < id_comp-1) 
Select id_comp,
case when id_comp = 1 then 1 else
replace((Select i + '' as 'data()' from a t2 where t1.id_comp = t2.id_comp for xml path('')) + convert(varchar(5),id_comp) + (Select i + '' as 'data()' from a t2 where t1.id_comp = t2.id_comp order by i desc for xml path('')), ' ', '')
end
From a t1 group by id_comp

with a as(SELECT t1.d + t2.d * 10 as i
FROM (VALUES (0), (1), (2), (3), (4), (5), (6), (7), (8), (9) ) AS t1 (d)
CROSS JOIN (VALUES (0), (1), (2), (3), (4), (5), (6), (7), (8), (9) ) AS t2 (d)
),
b as(Select id_comp, i+1 as i From Company c join a on c.id_comp > a.i)
Select distinct id_comp,
replace((Select i + '' as 'data()' from b t2 where t1.id_comp = t2.id_comp for xml path('')) +
isnull((Select i + '' as 'data()' from b t2 where t1.id_comp = t2.id_comp and i < t1.id_comp order by i desc for xml path('')),''), ' ', '')
from b t1

----118

with a as(SELECT t1.d + t2.d * 10 as i
FROM (VALUES (0), (1), (2), (3), (4), (5), (6), (7), (8), (9) ) AS t1 (d)
CROSS JOIN (VALUES (0), (1), (2), (3), (4), (5), (6), (7), (8), (9) ) AS t2 (d)
),
b as(Select dateadd(year, i, date) dt From Battles, a),
c as(Select distinct year(dt) dt from b, Battles where year(dt) >= year(date)
and (year(dt)%4 = 0 and year(dt)%100 > 0 or year(dt)%400 = 0)),
d as(Select dateadd(month, 3, convert(char(10),dt, 120)) dt From c),
e as (Select dt, case
when Datename(dw, dt) = 'Monday' then dateadd(dd, 1, dt)
when Datename(dw, dt) = 'Tuesday' then dateadd(dd, 7, dt)
when Datename(dw, dt) = 'Wednesday' then dateadd(dd, 6, dt)
when Datename(dw, dt) = 'Thursday' then  dateadd(dd, 5, dt)
when Datename(dw, dt) = 'Friday' then dateadd(dd, 4, dt)
when Datename(dw, dt) = 'Saturday' then dateadd(dd, 3, dt)
when Datename(dw, dt) = 'Sunday' then dateadd(dd, 2, dt)
end elect
From d)
Select name, convert(char(10), date, 120), min(convert(char(10), elect, 120)) From Battles, e where date <= elect
Group by name, date


-----94

With a as(
Select i = 0
Union all
Select i + 1 from a where i < 6),
b as(Select date, count(distinct p.trip_no) qty From Pass_in_trip p join Trip t on t.trip_no = p.trip_no where town_from = 'Rostov' group by date)
Select date, dateadd(dd,i,date), dense_rank() over(order by date) from b
Cross apply (Select * from a) inc

With a as(
Select i = 0
Union all
Select i + 1 from a where i < 6),
b as(Select date, count(distinct p.trip_no) qty From Pass_in_trip p join Trip t on t.trip_no = p.trip_no where town_from = 'Rostov' group by date),
c as(Select date, dateadd(dd,i,date) days, dense_rank() over(order by date) rank from b
Cross apply (Select * from a) inc)
Select distinct days, 
iif(qty is null, 0, qty) From c left join b on days = b.date


with a as(Select date, date as date2 From Pass_in_trip
Union all
Select date, dateadd(dd,1, date2)  from a where date2 < dateadd(dd, 7, date))
Select * from a group by date, date2


----97

with a as(Select 
code, 
convert(numeric(6,2),speed) speed, 
convert(numeric(6,2),ram) ram, 
convert(numeric(6,2),price) price, 
convert(numeric(6,2),screen) screen 
From Laptop)
Select i, code from a 
unpivot
(
i for v in (speed,ram,price,screen)
)x order by i

---131

With a as(Select town_to city, len(town_to) l From trip
Union
Select town_from city, len(town_from) l From trip),
b as(SELECT t1.d + t2.d * 10 as i
FROM (VALUES (0), (1), (2), (3), (4), (5), (6), (7), (8), (9) ) AS t1 (d)
CROSS JOIN (VALUES (0), (1), (2), (3), (4), (5), (6), (7), (8), (9) ) AS t2 (d)
),
c as(Select distinct city, 'o' as let, charindex('o', city, charindex('e', city) + i) as j From a, b where i < l
union
Select distinct city,'e', charindex('e', city, charindex('e', city) + i) as j From a, b where i < l
union
Select distinct city,'a', charindex('a', city, charindex('a', city) + i) as j From a, b where i < l
union
Select distinct city,'i', charindex('i', city, charindex('i', city) + i) as j From a, b where i < l
union
Select distinct city,'u', charindex('u', city, charindex('u', city) + i) as j From a, b where i < l),
d as(Select city, let, count(j) i From c where j > 0 group by city, let)
Select city From d where i = (Select max(i) From d t2 where t2.city = d.city) group by city having count(let) > 1 and sum(i)%count(let) = 0

-----134

with a as(Select q_id, b_v_id From utq Left join utb on q_id = b_q_id group by q_id, b_v_id having coalesce(sum(b_vol),0) < 255),
b as(Select v_color, sum(remain) from (Select v_id, v_color, 255-sum(b_vol) remain From utv left join utb on utb.b_v_id = utv.v_id group by v_id, v_color having sum(b_vol) != 255) x group by v_color)


---128

with a as(Select point, date From Outcome_o
Union
Select point, date From Outcome),
o1 as(Select a.point point, a.date date, out From a 
left join Outcome_o o on a.point = o.point and a.date = o.date),
o2 as(Select a.point point, a.date date, out From a 
left join Outcome o on a.point = o.point and a.date = o.date),
s1 as(Select point, date, count(*) qty, sum(out) val From o1 group by point, date),
s2 as(Select point, date, count(*) qty, sum(out) val From o2 group by point, date)
Select s1.point, s1.date,
case when s1.val = s2.val then 'both'
when (s1.qty > s2.qty and s1.val > s2.val) then 'more than once a day'
when (s1.qty > s2.qty and s1.val < s2.val) then 'once a day'
when (s1.qty < s2.qty and s1.val > s2.val) then 'once a day'
when (s1.qty < s2.qty and s1.val < s2.val) then 'more than once a day'
when (s1.qty = s2.qty and s1.val < s2.val) then 'once a day'
when (s1.qty = s2.qty and s1.val > s2.val) then 'once a day'
end
from s1, s2 where s1.point = s2.point and s1.date = s2.date
