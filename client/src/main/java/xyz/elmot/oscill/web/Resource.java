package xyz.elmot.oscill.web;

import java.io.InputStream;
import java.util.function.Supplier;

/**
 * (c) elmot on 10.3.2017.
 */
public class Resource {
    public final String mimeType;
    public final Supplier<InputStream> data;

    public Resource(String mimeType, Supplier<InputStream> data) {
        this.mimeType = mimeType;
        this.data = data;
    }
}
