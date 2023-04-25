load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "tinytest",
    srcs = ["test.cpp"],
    hdrs = ["test.h"],
)

cc_library(
    name = "abilities",
    srcs = ["Abilities.cpp"],
    hdrs = ["Abilities.h"],
)

cc_test(
    name = "abilities_test",
    srcs = ["Abilities_test.cpp"],
    deps = [
        ":abilities",
        ":tinytest",
    ],
)

cc_library(
    name = "archetypes",
    srcs = ["Archetypes.cpp"],
    hdrs = ["Archetypes.h"],
)

cc_test(
    name = "archetypes_test",
    srcs = ["Archetypes_test.cpp"],
    deps = [
        ":archetypes",
        ":tinytest",
    ],
)

cc_library(
    name = "attributes",
    srcs = ["Attributes.cpp"],
    hdrs = ["Attributes.h"],
)

cc_test(
    name = "attributes_test",
    srcs = ["Attributes_test.cpp"],
    deps = [
        ":attributes",
        ":tinytest",
    ],
)

cc_library(
    name = "backgrounds",
    srcs = ["Backgrounds.cpp"],
    hdrs = ["Backgrounds.h"],
)

cc_test(
    name = "backgrounds_test",
    srcs = ["Backgrounds_test.cpp"],
    deps = [
        ":backgrounds",
        ":tinytest",
    ],
)

cc_library(
    name = "character",
    srcs = ["Character.cpp"],
    hdrs = ["Character.h"],
    deps = [
        ":abilities",
        ":attributes",
        ":backgrounds",
        ":clans",
        ":colors",
        ":derangements",
        ":disciplines",
        ":ranks",
        ":virtues",
    ],
)

cc_test(
    name = "character_test",
    srcs = ["Character_test.cpp"],
    deps = [
        ":character",
        ":tinytest",
    ],
)

cc_library(
    name = "clans",
    srcs = ["Clans.cpp"],
    hdrs = ["Clans.h"],
)

cc_test(
    name = "clans_test",
    srcs = ["Clans_test.cpp"],
    deps = [
        ":clans",
        ":tinytest",
    ],
)

cc_library(
    name = "colors",
    srcs = ["Colors.cpp"],
    hdrs = ["Colors.h"],
)

cc_test(
    name = "colors_test",
    srcs = ["Colors_test.cpp"],
    deps = [
        ":colors",
        ":tinytest",
    ],
)

cc_library(
    name = "derangements",
    srcs = ["Derangements.cpp"],
    hdrs = ["Derangements.h"],
    deps = [":colors"],
)

cc_test(
    name = "derangements_test",
    srcs = ["Derangements_test.cpp"],
    deps = [
        ":derangements",
        ":tinytest",
    ],
)

cc_library(
    name = "disciplines",
    srcs = ["Disciplines.cpp"],
    hdrs = ["Disciplines.h"],
)

cc_test(
    name = "disciplines_test",
    srcs = ["Disciplines_test.cpp"],
    deps = [
        ":disciplines",
        ":tinytest",
    ],
)

cc_library(
    name = "freebies",
    srcs = ["Freebies.cpp"],
    hdrs = ["Freebies.h"],
)

cc_test(
    name = "freebies_test",
    srcs = ["Freebies_test.cpp"],
    deps = [
        ":freebies",
        ":tinytest",
    ],
)

cc_library(
    name = "genders",
    srcs = ["Genders.cpp"],
    hdrs = ["Genders.h"],
)

cc_test(
    name = "genders_test",
    srcs = ["Genders_test.cpp"],
    deps = [
        ":genders",
        ":tinytest",
    ],
)

cc_library(
    name = "character_generator",
    srcs = ["CharacterGenerator.cpp"],
    hdrs = ["CharacterGenerator.h"],
    deps = [
        "archetypes",
        "character",
        "freebies",
        "genders",
        "menus",
    ],
)

cc_test(
    name = "character_generator_test",
    srcs = ["CharacterGenerator_test.cpp"],
    deps = [
        ":character_generator",
        ":tinytest",
    ],
)

# cc_library(
#     name = "main",
#     srcs = ["main.cpp"],
#     hdrs = ["main.h"],
# )

# cc_test(
#     name = "main_test",
#     srcs = ["main_test.cpp"],
#     deps = [
#         ":main",
#         ":tinytest",
#     ],
# )

cc_library(
    name = "menus",
    srcs = ["Menus.cpp"],
    hdrs = ["Menus.h"],
    deps = [
        ":colors",
        ":random",
        ":utils",
    ],
)

cc_test(
    name = "menus_test",
    srcs = ["Menus_test.cpp"],
    deps = [
        ":menus",
        ":tinytest",
    ],
)

cc_library(
    name = "random",
    srcs = ["Random.cpp"],
    hdrs = ["Random.h"],
)

cc_test(
    name = "random_test",
    srcs = ["Random_test.cpp"],
    deps = [
        ":random",
        ":tinytest",
    ],
)

cc_library(
    name = "ranks",
    srcs = ["Ranks.cpp"],
    hdrs = ["Ranks.h"],
)

cc_test(
    name = "ranks_test",
    srcs = ["Ranks_test.cpp"],
    deps = [
        ":ranks",
        ":tinytest",
    ],
)

cc_binary(
    name = "sbf",
    srcs = [
        "sbf.cpp",
        "sbf.h",
    ],
    deps = [
        ":character_generator",
        ":menus",
    ],
)

# cc_test(
#     name = "sbf_test",
#     srcs = ["sbf_test.cpp"],
#     deps = [
#         ":sbf",
#         ":tinytest",
#     ],
# )

cc_library(
    name = "utils",
    srcs = ["Utils.cpp"],
    hdrs = ["Utils.h"],
)

cc_test(
    name = "utils_test",
    srcs = ["Utils_test.cpp"],
    deps = [
        ":tinytest",
        ":utils",
    ],
)

cc_library(
    name = "virtues",
    srcs = ["Virtues.cpp"],
    hdrs = ["Virtues.h"],
)

cc_test(
    name = "virtues_test",
    srcs = ["Virtues_test.cpp"],
    deps = [
        ":tinytest",
        ":virtues",
    ],
)
