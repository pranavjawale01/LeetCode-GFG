import pandas as pd

def list_products(products: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    orders["order_date"] = orders["order_date"].dt.strftime("%Y-%m")
    orders = orders[orders["order_date"] == "2020-02"].reset_index().drop(columns = ["index"])
    orders = orders.groupby(["product_id"])["unit"].sum().reset_index()
    result = pd.merge(orders,products,how = "inner",on="product_id")
    return result[result["unit"] >= 100][["product_name","unit"]]