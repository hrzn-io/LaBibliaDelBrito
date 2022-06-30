package io.hrzn.ex2;

import java.util.Scanner;

public class Map {

    private int matrix[][] = new int[100][100];
    private int n, v;

    Map() {
        n = v = 0;
        try (Scanner in = new Scanner(System.in)) {
            do {
                System.out.println("set map size (between 0 and 99");
                n = in.nextInt();
            } while (n < 0 || n > 99);
            System.out.println("set the value :");
            v = in.nextInt();
        } catch (Exception e) {
            System.err.println("not a valid interger");
        }
    }

    public void move() {
        boolean lock = false;
        boolean tmp_lock = lock;
        for (int y = 0; y < n; y++) {
            if (tmp_lock == lock) {
                int x = 0;
                matrix[y][x] = v;
                print();
                for (x = 0; x < n - 1; x++) {
                    matrix[y][x + 1] = v;
                    matrix[y][x] = 0;
                    print();
                }
                matrix[y][x] = 0;
                tmp_lock = !lock;
            } else {
                int x = n - 1;
                matrix[y][x] = v;
                print();
                for (x = n - 1; x > 0; x--) {
                    matrix[y][x - 1] = v;
                    matrix[y][x] = 0;
                    print();
                }
                matrix[y][x] = 0;
                tmp_lock = !lock;
            }
        }
    }

    public void print() {
        for (int x = 0; x <= n - 1; x++) {
            for (int y = 0; y <= n - 1; y++) {
                System.out.print(matrix[x][y] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
