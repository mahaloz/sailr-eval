import toml


class SAILRTarget:
    def __init__(self, *args,
                 package_name=None,
                 source_remote=None,
                 download=None,
                 post_download_cmds=None,
                 version=None,
                 package_dir=None,
                 pre_make_cmds=None,
                 make_cmd=None,
                 post_make_cmds=None,
                 source_dir=None,
                 remote_type=None,
                 override_make_vars=None,
                 apply_patch=None,
                 rename_dash_files=False,
                 windows_project=False,
                 skip_compilation=False,
                 subset_compilation=None,
                 skip_file_copy=False,
                 c_compiler=None,
                 cpp_compiler=None,
                 **kwargs
                 ):
        """
        @param args:
        @param package_name: The name associated with this project, used for script settings lookup (this file)
        @param source_remote: The Git or Tar download location
        @param download: True/False, weather this should be downloaded when compiled
        @param post_download_cmds: Shell commands that should be run only after downloading for the first time
        @param version: Version string, used for Git checkout or documentation
        @param package_dir: The name this should be cloned as, and the place entered for compilation (can have subdir)
        @param pre_make_cmds: Commands to run before a make (usually a ./configure)
        @param make_cmd: Usually just 'make'
        @param post_make_cmds: Commands to run after a make (usually a 'rm -rf' of sorts)
        @param source_dir: Directory inside the @package_dir that's used to copy source (and object files) out of
        @param remote_type: git/tar
        @param override_make_vars:
        @param apply_patch: True/False, to apply a patch that is located in the 'targets/patches' folder
        @param rename_dash_files: True/False, Renames files like [expat-foo, expat-bar] to [foo, bar]
        @param kwargs:
        """
        self.package_name = package_name
        self.source_remote = source_remote
        self.download = download or False
        self.post_download_cmds = post_download_cmds
        self.version = version
        self.package_dir = package_dir
        self.pre_make_cmds = pre_make_cmds
        self.make_cmd = make_cmd
        self.post_make_cmds = post_make_cmds
        self.source_dir = source_dir
        self.remote_type = remote_type
        self.override_make_vars = override_make_vars or False
        self.apply_patch = apply_patch
        self.rename_dash_files = rename_dash_files
        self.windows_project = windows_project
        self.skip_compilation = skip_compilation
        self.subset_compilation = subset_compilation
        self.skip_file_copy = skip_file_copy
        self.c_compiler = c_compiler
        self.cpp_compiler = cpp_compiler

    @classmethod
    def from_toml(cls, toml_path):
        with open(toml_path, "r") as fp:
            data = toml.load(fp)

        return cls(**data)
