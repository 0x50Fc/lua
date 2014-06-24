
root = E("GLSceneElement")
    :add(
        E("GLScreenElement")
        :add(
            E("GLGamepadElement")
            :add(
                E("GLLayerElement")
                :setValue("background-color","#00ff00")
                :setValue("name","begin")
                :setValue("alpha",0.4)
                :call("setSize",44,44)
            )
            :add(
                E("GLLayerElement")
                :setValue("background-color","#ff0000")
                :setValue("name","to")
                :setValue("alpha",0.6)
                :call("setSize",22,22)
            )
            :add(
                E("GLLayerElement")
                :setValue("name","buttons")
                :call("setSize",152,44)
                :add(
                    E("GLGamepadButtonElement")
                    :setValue("background-color","#ff0000")
                    :setValue("alpha",0.6)
                    :setValue("name","A")
                    :call("setFrame",0,0,44,44)
                )
                :add(
                    E("GLGamepadButtonElement")
                    :setValue("background-color","#00ff00")
                    :setValue("alpha",0.6)
                    :setValue("name","B")
                    :call("setFrame",54,0,44,44)
                )
                :add(
                    E("GLGamepadButtonElement")
                    :setValue("background-color","#0000ff")
                    :setValue("alpha",0.6)
                    :setValue("name","C")
                    :call("setFrame",108,0,44,44)
                )
            )
        )
    );

function root:doAction(object)

    local action = O(object);

    print(action:value("buttonName"));
    print(action:value("actionType"));

end