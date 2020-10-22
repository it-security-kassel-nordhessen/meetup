package data.session.token;

import java.io.*;
import data.session.token.AccessTokenUser;
import data.productcatalog.ProductTemplate;

public class Starter
{
    public static void main(String[] args) throws Exception {
      System.out.println("Using args 1:" + args[0]);
      ProductTemplate pt = new ProductTemplate(args[0]);
      // serialization
      FileOutputStream fos = new FileOutputStream("serialsqli.txt");
      ObjectOutputStream oos = new ObjectOutputStream(fos);
      oos.writeObject(pt);
      
   }

}
