package io.hrzn.ex1;

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
        for (int x = 0; x < n; x++) {
            if (tmp_lock == lock) {
                int y = 0;
                matrix[y][x] = v;
                print();
                for (y = 0; y < n - 1; y++) {
                    matrix[y + 1][x] = v;
                    matrix[y][x] = 0;
                    print();
                }
                matrix[y][x] = 0;
                tmp_lock = !tmp_lock;
            } else {
                int y = n - 1;
                matrix[y][x] = v;
                print();
                for (y = n - 1; y > 0; y--) {
                    matrix[y - 1][x] = v;
                    matrix[y][x] = 0;
                    print();
                }
                matrix[y][x] = 0;
                tmp_lock = !tmp_lock;
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
