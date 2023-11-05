//-------
// Compression Functions
//-------

// CompressData
mrb_value mrb_compress_data(mrb_state *mrb, mrb_value self)
{
    const unsigned char *data;
    mrb_int datasize;
    int *compdatasize;
    mrb_get_args(mrb, "zii", &data, &datasize, &compdatasize);
    unsigned char *compressed = CompressData(data, datasize, compdatasize);
    mrb_value obj = mrb_str_new_cstr(mrb, (const char *)compressed);
    MemFree(compressed);
    return obj;
}

// DecompressData
mrb_value mrb_decompress_data(mrb_state *mrb, mrb_value self)
{
    const unsigned char *data;
    mrb_int compdatasize;
    int *datasize;
    mrb_get_args(mrb, "zii", &data, &compdatasize, &datasize);
    unsigned char *decompressed = DecompressData(data, compdatasize, datasize);
    mrb_value obj = mrb_str_new_cstr(mrb, (const char *)decompressed);
    MemFree(decompressed);
    return obj;
}

// EncodeDataBase64
mrb_value mrb_encode_data_base64(mrb_state *mrb, mrb_value self)
{
    const unsigned char *data;
    mrb_int datasize;
    int *outputsize;
    mrb_get_args(mrb, "zii", &data, &datasize, &outputsize);
    char *base64 = EncodeDataBase64(data, datasize, outputsize);
    mrb_value obj = mrb_str_new_cstr(mrb, (const char *)base64);
    MemFree(base64);
    return obj;
}

// DecodeDataBase64
mrb_value mrb_decode_data_base64(mrb_state *mrb, mrb_value self)
{
    const unsigned char *data;
    int *outputsize;
    mrb_get_args(mrb, "zi", &data, &outputsize);
    unsigned char *base64 = DecodeDataBase64(data, outputsize);
    mrb_value obj = mrb_str_new_cstr(mrb, (const char *)base64);
    MemFree(base64);
    return obj;
}

void mrb_raylib_setup_compression(mrb_state *mrb, struct RClass *raylib_module)
{
    mrb_define_module_function(mrb, raylib_module, "compress_data", mrb_compress_data, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "decompress_data", mrb_decompress_data, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "encode_data_base64", mrb_encode_data_base64, MRB_ARGS_REQ(3));
    mrb_define_module_function(mrb, raylib_module, "decode_data_base64", mrb_decode_data_base64, MRB_ARGS_REQ(2));
}
