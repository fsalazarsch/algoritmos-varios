static PyObject *
scribe (PyObject *self, PyObject *args)
{
    const int command;
    int n = 0;
    if (!PyArg_ParseTuple(args, "i", &command))
        return NULL;
    for (n = 0; n <= command; n++){
        printf("%d ",n);
    }
    return Py_BuildValue("i",command);
}
