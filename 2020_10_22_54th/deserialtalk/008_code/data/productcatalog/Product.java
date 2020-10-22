package data.productcatalog;

import java.sql.ResultSet;

public class Product
{
    public static Product from(ResultSet resultSet)
    {
        return new Product();
    }
}
