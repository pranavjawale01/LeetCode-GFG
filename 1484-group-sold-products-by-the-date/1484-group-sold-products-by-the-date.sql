/* Write your PL/SQL query statement below */
SELECT to_char(SELL_DATE,'yyyy-mm-dd') sell_date,
COUNT(PRODUCT) num_sold,
listagg(product ,',') within group(order by sell_date) products
from (select distinct * from activities) group by sell_date
order by sell_date