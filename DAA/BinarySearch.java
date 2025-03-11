import java.util.Scanner;

public class BinarySearch {
    
    // Recursive binary search function
    public static int BS(int[] a, int l, int h, int x) {
        if (h >= l) {
            int mid = (h + l) / 2;

            if (a[mid] == x) {
                return mid; // Element found at index mid
            }

            if (a[mid] < x) {
                return BS(a, mid + 1, h, x); // Search in the right half
            } else {
                return BS(a, l, mid - 1, x); // Search in the left half
            }
        }


        return -1; // Element not found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = scanner.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter " + n + " sorted elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.print("Enter the element to search: ");
        int x = scanner.nextInt();

        int result = BS(arr, 0, n - 1, x);

        if (result != -1) {
            System.out.println("Element found at index " + result);
        } else {
            System.out.println("Element not found");
        }

        scanner.close();
    }
}
