package com.company;


import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class DataSetGenerator {
  public void generate(String path, int amountOfLines) throws IOException {
    BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(path));
    for (int i = 0; i < amountOfLines; i++) {
      String line = "";
      for (int j = 0; j < 5; j++) {
        if (j == 4) {
          line += random();
        } else {
          line += (random() + ",");
        }
      }
      bufferedWriter.write(line);
      bufferedWriter.newLine();
    }
    bufferedWriter.close();
  }


  public static int random() {
    return (int) (Math.random() * 10);
  }

  public static void main(String[] args) throws IOException {
    DataSetGenerator dataSetGenerator = new DataSetGenerator();
    String path = "";
//    BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(path));
    for (int i = 1; i < 11; i++) {
      File file;
      path = "/Users/timuribragimov/CLionProjects/semester-work-gauss-jordan/dataset/data/";
      if (i == 10) {
        path += "10";
      } else {
        path += "0" + i;
      }
      file = new File(path);
      file.mkdir();
    }

    path ="/Users/timuribragimov/CLionProjects/semester-work-gauss-jordan/dataset/data/";

    for (int i = 1; i < 11; i++) {
      if (i == 10) {
        path += "10";
      } else {
        path += "0" + i;
      }
      String currentPath = path;
      int amountOfLines = 100;
      for (int j = 1; amountOfLines != 1000000; j++) {
        currentPath = currentPath + "/" + amountOfLines + ".csv";
        dataSetGenerator.generate(currentPath, amountOfLines);
        if (j % 2 != 0) {
          amountOfLines = amountOfLines * 5;
        } else {
          amountOfLines = amountOfLines * 2;
        }
        currentPath = path;
      }
      path ="/Users/timuribragimov/CLionProjects/semester-work-gauss-jordan/dataset/data/";
    }
  }
}
