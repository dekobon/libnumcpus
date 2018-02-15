# libnumcpus.so

This library spoofs the processor count in the JVM allowing applications that
auto-configure thread pools based on detected CPU core count to configure to
a value that you specify.

This library was presented as an [answer on Stack Overflow](https://stackoverflow.com/a/22762558/33611)
by [apangin](https://stackoverflow.com/users/3448419/apangin) in 2014, so it
falls under the [CC-BY-SA](./LICENSE).

## Building

Run GNU Make:
```
$ make
```

This will output the library `libnumcpus.so`


## Installing

In the environment scope in which you execute your Java application, set
the enviroment variable `_NUM_CPUS` to the value of the number of CPUs
that you want to visualize to Java. Then set the path in `LD_PRELOAD` 
(or `LD_PRELOAD_64` on illumos/SmartOS/Solaris) to the `libnumcpus.so` library. For example:

```java
public class AvailableProcessors {
    public static void main(String... args) {
        System.out.println(Runtime.getRuntime().availableProcessors());
    }
}
```

```
$ LD_PRELOAD=/path/to/libnumcpus.so _NUM_CPUS=2 java AvailableProcessors
2
```
