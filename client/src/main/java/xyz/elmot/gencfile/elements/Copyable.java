package xyz.elmot.gencfile.elements;

import com.sun.webkit.graphics.WCStroke;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * (c) elmot on 16.4.2017.
 */
public interface Copyable {
    void copyFrom(Copyable o);

    default <V extends Copyable> List<V> copy(List<V> srcList) {
        ArrayList<V> objects = new ArrayList<>(srcList.size());
        for (V v : srcList) {
            try {
                V copy = (V) v.getClass().newInstance();
                copy.copyFrom(v);
                objects.add( copy);
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
        return objects;
    }

}
